#include "html.h"
#include "render_item.h"
#include "document.h"

int litehtml::render_item_asset::render(point p, const containing_block_context &containing_block_size, bool second_pass)
{
    int parent_width = containing_block_size.width;

    calc_outlines(parent_width);

    m_pos.move_to(p);

    document::ptr doc = src_el()->get_document();

    litehtml::size sz;
    src_el()->get_content_size(sz, containing_block_size.width);

    m_pos.width		= sz.width;
    m_pos.height	= sz.height;
    #if H3ML
    m_pos.depth 	= sz.depth;
    #endif

    src_el()->css_w().set_line_height(height());

    if(src_el()->css().get_height().is_predefined() && src_el()->css().get_width().is_predefined())
    {
        m_pos.height	= sz.height;
        m_pos.width		= sz.width;
        #if H3ML
        m_pos.depth 	= sz.depth;
        #endif

        // check for max-width
        if(!src_el()->css().get_max_width().is_predefined())
        {
            int max_width = doc->to_pixels(src_el()->css().get_max_width(), src_el()->css().get_font_size(), parent_width);
            if(m_pos.width > max_width)
            {
                m_pos.width = max_width;
            }
            if(sz.width)
            {
                m_pos.height = (int) ((float) m_pos.width * (float) sz.height / (float)sz.width);
            } else
            {
                m_pos.height = sz.height;
            }
        }

        // check for max-height
        if(!src_el()->css().get_max_height().is_predefined())
        {
            int max_height = calc_max_height(sz.height, containing_block_size.height);
            if(m_pos.height > max_height)
            {
                m_pos.height = max_height;
            }
            if(sz.height)
            {
                m_pos.width = (int) ((float)m_pos.height * (float)sz.width / (float)sz.height);
            } else
            {
                m_pos.width = sz.width;
            }
        }
    } else if(!src_el()->css().get_height().is_predefined() && src_el()->css().get_width().is_predefined())
    {
        if (!get_predefined_height(m_pos.height, containing_block_size.height))
        {
            m_pos.height = (int)src_el()->css().get_height().val();
        }

        // check for max-height
        if(!src_el()->css().get_max_height().is_predefined())
        {
            int max_height = calc_max_height(sz.height, containing_block_size.height);
            if(m_pos.height > max_height)
            {
                m_pos.height = max_height;
            }
        }

        if(sz.height)
        {
            m_pos.width = (int) ((float)m_pos.height * (float)sz.width / (float)sz.height);
        } else
        {
            m_pos.width = sz.width;
        }
    } else if(src_el()->css().get_height().is_predefined() && !src_el()->css().get_width().is_predefined())
    {
        m_pos.width = (int) src_el()->css().get_width().calc_percent(parent_width);

        // check for max-width
        if(!src_el()->css().get_max_width().is_predefined())
        {
            int max_width = doc->to_pixels(src_el()->css().get_max_width(), src_el()->css().get_font_size(), parent_width);
            if(m_pos.width > max_width)
            {
                m_pos.width = max_width;
            }
        }

        if(sz.width)
        {
            m_pos.height = (int) ((float) m_pos.width * (float) sz.height / (float)sz.width);
        } else
        {
            m_pos.height = sz.height;
        }
    } else
    {
        m_pos.width		= (int) src_el()->css().get_width().calc_percent(parent_width);
        m_pos.height	= 0;
        #if H3ML
        m_pos.depth		= 0;
        #endif
        if (!get_predefined_height(m_pos.height, containing_block_size.height))
        {
            m_pos.height = (int)src_el()->css().get_height().val();
        }

        // check for max-height
        if(!src_el()->css().get_max_height().is_predefined())
        {
            int max_height = calc_max_height(sz.height, containing_block_size.height);
            if(m_pos.height > max_height)
            {
                m_pos.height = max_height;
            }
        }

        // check for max-height
        if(!src_el()->css().get_max_width().is_predefined())
        {
            int max_width = doc->to_pixels(src_el()->css().get_max_width(), src_el()->css().get_font_size(), parent_width);
            if(m_pos.width > max_width)
            {
                m_pos.width = max_width;
            }
        }
    }

    m_pos.x	+= content_offset_left();
    m_pos.y += content_offset_top();
    #if H3ML
    m_pos.z += content_offset_front();
    #endif

    return m_pos.width + content_offset_left() + content_offset_right();
}

int litehtml::render_item_asset::calc_max_height(int asset_height, int containing_block_height)
{
    document::ptr doc = src_el()->get_document();
    return doc->to_pixels(src_el()->css().get_max_height(), src_el()->css().get_font_size(),
						  containing_block_height == 0 ? asset_height : containing_block_height);
}