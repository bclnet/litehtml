#if H3ML
#include "html.h"
#include "el_asset.h"
#include "render_asset.h"

litehtml::el_asset::el_asset(const document::ptr& doc) : html_tag(doc)
{
	m_css.set_display(display_inline_block);
}

void litehtml::el_asset::get_content_size( size& sz, int max_width )
{
	get_document()->container()->get_asset_size(m_src.c_str(), 0, &m_attrs, sz);
}

bool litehtml::el_asset::is_replaced() const
{
	return true;
}

void litehtml::el_asset::parse_attributes()
{
	m_src = get_attr("src", "");

	const char* attr_height = get_attr("height");
	if(attr_height)
	{
		m_style.add_property(_height_, attr_height);
	}
	const char* attr_width = get_attr("width");
	if(attr_width)
	{
		m_style.add_property(_width_, attr_width);
	}
	#if H3ML
	const char* attr_depth = get_attr("depth");
	if(attr_depth)
	{
		m_style.add_property(_depth_, attr_depth);
	}
	#endif
}

void litehtml::el_asset::draw(uint_ptr hdc, point p, const position *clip, const std::shared_ptr<render_item> &ri)
{
	position pos = ri->pos();
	pos.x += p.x;
	pos.y += p.y;
	#if H3ML
	pos.z += p.z;
	#endif

	position el_pos = pos;
	el_pos += ri->get_paddings();
	el_pos += ri->get_borders();

	// draw standard background here
	if (el_pos.does_intersect(clip))
	{
		const background* bg = get_background();
		if (bg)
		{
			std::vector<background_paint> bg_paint;
			init_background_paint(pos, bg_paint, bg, ri);

			get_document()->container()->draw_background(hdc, bg_paint);
		}
	}

	// draw image as background
	if(pos.does_intersect(clip))
	{
		if (pos.width > 0 && pos.height > 0) {
			asset_paint bg;
			bg.image				= m_src;
			bg.attrs				= &m_attrs;
			bg.clip_box				= pos;
			bg.origin_box			= pos;
			bg.border_box			= pos;
			bg.border_box			+= ri->get_paddings();
			bg.border_box			+= ri->get_borders();
			bg.image_size.width		= pos.width;
			bg.image_size.height	= pos.height;
			#if H3ML
			bg.image_size.depth		= pos.depth;
			#endif
			bg.border_radius		= css().get_borders().radius.calc_percents(bg.border_box.sz());
			bg.position				= pos.p();
			get_document()->container()->draw_asset(hdc, {bg});
		}
	}

	// draw borders
	if (el_pos.does_intersect(clip))
	{
		position border_box = pos;
		border_box += ri->get_paddings();
		border_box += ri->get_borders();

		borders bdr = css().get_borders();
		bdr.radius = css().get_borders().radius.calc_percents(border_box.sz());

		get_document()->container()->draw_borders(hdc, bdr, border_box, is_root());
	}
}

void litehtml::el_asset::compute_styles(bool recursive)
{
	html_tag::compute_styles(recursive);

	if(!m_src.empty())
	{
		if(!css().get_height().is_predefined() && !css().get_width().is_predefined())
		{
			get_document()->container()->load_asset(m_src.c_str(), nullptr, &m_attrs, true);
		} else
		{
			get_document()->container()->load_asset(m_src.c_str(), nullptr, &m_attrs, false);
		}
	}
}

litehtml::string litehtml::el_asset::dump_get_name()
{
	return "asset src=\"" + m_src + "\"";
}

std::shared_ptr<litehtml::render_item> litehtml::el_asset::create_render_item(const std::shared_ptr<render_item>& parent_ri)
{
	auto ret = std::make_shared<render_item_asset>(shared_from_this());
	ret->parent(parent_ri);
	return ret;
}
#endif