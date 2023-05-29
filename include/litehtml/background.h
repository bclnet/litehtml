#ifndef LH_BACKGROUND_H
#define LH_BACKGROUND_H

#include "types.h"
#include "css_length.h"
#include "css_position.h"
#include "web_color.h"
#include "borders.h"

namespace litehtml
{
	class background
	{
	public:
		string_vector			m_image;
		string					m_baseurl;
		web_color				m_color;
		int_vector				m_attachment;
		length_vector			m_position_x;
		length_vector			m_position_y;
		#if H3ML
		length_vector			m_position_z;
		#endif
		size_vector				m_size;
		int_vector				m_repeat;
		int_vector				m_clip;
		int_vector				m_origin;

		bool is_empty() const
		{
			if(m_color.alpha != 0) return false;
			if(m_image.empty()) return true;
			for(const auto& img : m_image)
			{
				if(!img.empty()) return false;
			}
			return true;
		}
	};

	class background_paint
	{
	public:
		string					image;
		string					baseurl;
		background_attachment	attachment;
		background_repeat		repeat;
		web_color				color;
		position				clip_box;
		position				origin_box;
		position				border_box;
		border_radiuses			border_radius;
		size					image_size;
		point					position;
		bool					is_root;

	public:
		background_paint()
		{
			attachment		= background_attachment_scroll;
			repeat			= background_repeat_repeat;
			color			= web_color::transparent;
			position		= point_zero;
			is_root			= false;
		}
	};

	#if H3ML
	class asset_paint
	{
	public:
		string					image;
		string					baseurl;
		string_map*				attrs;
		web_color				color;
		position				clip_box;
		position				origin_box;
		position				border_box;
		border_radiuses			border_radius;
		size					image_size;
		point					position;
		bool					is_root;

	public:
		asset_paint()
		{
			color			= web_color::transparent;
			position		= point_zero;
			is_root			= false;
		}
	};
	#endif
}

#endif  // LH_BACKGROUND_H
