#include "graph_container.h"

uint_ptr graph_container::create_font(const char* faceName, int size, int weight, font_style italic, unsigned int decoration, font_metrics* fm) { return container->create_font(faceName, size, weight, italic, decoration, fm); }
void graph_container::delete_font(uint_ptr hFont) { return container->delete_font(hFont); }
int graph_container::text_width(const char* text, uint_ptr hFont) { return container->text_width(text, hFont); }
void graph_container::draw_text(uint_ptr hdc, const char* text, uint_ptr hFont, web_color color, const position& pos) { container->draw_text(hdc, text, hFont, color, pos); }
int graph_container::pt_to_px(int pt) const { return container->pt_to_px(pt); }
int graph_container::get_default_font_size() const { return container->get_default_font_size(); }
const char* graph_container::get_default_font_name() const { return container->get_default_font_name(); }
void graph_container::load_image(const char* src, const char* baseurl, bool redraw_on_ready) { container->load_image(src, baseurl, redraw_on_ready); }
void graph_container::get_image_size(const char* src, const char* baseurl, litehtml::size& sz) { container->get_image_size(src, baseurl, sz); }
void graph_container::draw_background(uint_ptr hdc, const std::vector<background_paint>& bg) { container->draw_background(hdc, bg); }
#if H3ML
void graph_container::load_asset(const char* src, const char* baseurl, const litehtml::string_map* attrs, bool redraw_on_ready) { container->load_asset(src, baseurl, attrs, redraw_on_ready); }
void graph_container::get_asset_size(const char* src, const char* baseurl, const litehtml::string_map* attrs, litehtml::size& sz) { container->get_asset_size(src, baseurl, attrs, sz); }
void graph_container::draw_asset(uint_ptr hdc, const std::vector<litehtml::asset_paint>& bg) { container->draw_asset(hdc, bg); }
#endif
void graph_container::draw_borders(uint_ptr hdc, const borders& borders, const position& pos, bool root) { container->draw_borders(hdc, borders, pos, root); }
void graph_container::draw_list_marker(uint_ptr hdc, const list_marker& marker) { container->draw_list_marker(hdc, marker); }
element::ptr graph_container::create_element(const char* tag_name,
	const string_map& attributes,
	const document::ptr& doc) { return container->create_element(tag_name, attributes, doc); }
void graph_container::get_media_features(media_features& media) const { container->get_media_features(media); }
void graph_container::get_language(string& language, string& culture) const { container->get_language(language, culture); }
void graph_container::link(const document::ptr& doc, const element::ptr& el) { container->link(doc, el); }

void graph_container::transform_text(string& text, text_transform tt) { container->transform_text(text, tt); }
void graph_container::set_clip(const position& pos, const border_radiuses& bdr_radius) { container->set_clip(pos, bdr_radius); }
void graph_container::del_clip() { container->del_clip(); }

void graph_container::set_caption(const char* caption) { container->set_caption(caption); }
void graph_container::set_base_url(const char* base_url) { container->set_base_url(base_url); }
void graph_container::on_anchor_click(const char* url, const element::ptr& el) { container->on_anchor_click(url, el); }
void graph_container::set_cursor(const char* cursor) { container->set_cursor(cursor); }
void graph_container::import_css(string& text, const string& url, string& baseurl) { container->import_css(text, url, baseurl); }
void graph_container::get_client_rect(position& client) const { container->get_client_rect(client); }
