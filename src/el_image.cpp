#include "html.h"
#include "el_image.h"
#include "render_image.h"

litehtml::el_image::el_image(const document::ptr& doc) : html_tag(doc)
{
	m_css.set_display(display_inline_block);
}

void litehtml::el_image::get_content_size( size& sz, int max_width )
{
	get_document()->container()->get_image_size(m_src.c_str(), 0, sz);
}

bool litehtml::el_image::is_replaced() const
{
	return true;
}

void litehtml::el_image::parse_attributes()
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

void litehtml::el_image::draw(uint_ptr hdc, point p, const position *clip, const std::shared_ptr<render_item> &ri)
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
			background_paint bg;
			bg.image				= m_src;
			bg.clip_box				= pos;
			bg.origin_box			= pos;
			bg.border_box			= pos;
			bg.border_box			+= ri->get_paddings();
			bg.border_box			+= ri->get_borders();
			bg.repeat				= background_repeat_no_repeat;
			bg.image_size.width		= pos.width;
			bg.image_size.height	= pos.height;
			#if H3ML
			bg.image_size.depth		= pos.depth;
			#endif
			bg.border_radius		= css().get_borders().radius.calc_percents(bg.border_box.sz());
			bg.position				= pos.p();
			get_document()->container()->draw_background(hdc, {bg});
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

void litehtml::el_image::compute_styles(bool recursive)
{
	html_tag::compute_styles(recursive);

	if(!m_src.empty())
	{
		if(!css().get_height().is_predefined() && !css().get_width().is_predefined())
		{
			get_document()->container()->load_image(m_src.c_str(), nullptr, true);
		} else
		{
			get_document()->container()->load_image(m_src.c_str(), nullptr, false);
		}
	}
}

litehtml::string litehtml::el_image::dump_get_name()
{
    return "img src=\"" + m_src + "\"";
}

std::shared_ptr<litehtml::render_item> litehtml::el_image::create_render_item(const std::shared_ptr<render_item>& parent_ri)
{
    auto ret = std::make_shared<render_item_image>(shared_from_this());
    ret->parent(parent_ri);
    return ret;
}
