/* a_basic.c */
gchar *o_save_objects(OBJECT *object_list);

/* f_print.c */
void f_print_set_line_width(FILE *fp, int width);
void f_print_set_color(FILE *fp, int color);
int f_print_header(TOPLEVEL *toplevel, FILE *fp, int paper_size_x, int paper_size_y, int eps);
void f_print_footer(FILE *fp);
void f_print_objects(TOPLEVEL *toplevel, FILE *fp, OBJECT *head, int start_x, int start_y, float scale, int unicode_count, gunichar *unicode_table);
int f_print_initialize_glyph_table(void);

/* g_rc.c */
int vstbl_lookup_str(const vstbl_entry *table, int size, const char *str);
int vstbl_get_val(const vstbl_entry *table, int index);
SCM g_rc_component_library(SCM path, SCM name);
SCM g_rc_component_library_command (SCM listcmd, SCM getcmd, SCM name);
SCM g_rc_component_library_funcs (SCM listfunc, SCM getfunc, SCM name);
SCM g_rc_component_library_search(SCM path);
SCM g_rc_source_library(SCM path);
SCM g_rc_source_library_search(SCM path);
SCM g_rc_world_size(SCM width, SCM height, SCM border);
SCM g_rc_reset_component_library(void);
SCM g_rc_reset_source_library(void);
SCM g_rc_default_series_name(SCM name);
SCM g_rc_untitled_name(SCM name);
SCM g_rc_font_directory(SCM path);
SCM g_rc_bitmap_directory(SCM path);
SCM g_rc_scheme_directory(SCM path);
SCM g_rc_bus_ripper_symname(SCM scmsymname);
SCM g_rc_postscript_prolog(SCM scmsymname);
SCM g_rc_map_font_character_to_file(SCM character_param, SCM file_param);
SCM g_rc_attribute_promotion(SCM mode);
SCM g_rc_promote_invisible(SCM mode);
SCM g_rc_keep_invisible(SCM mode);
SCM g_rc_always_promote_attributes(SCM scmsymname);

/* g_register.c */
void g_register_libgeda_funcs(void);
void g_register_libgeda_vars (void);

/* g_smob.c */
void g_init_attrib_smob(void);
SCM g_get_attrib_name_value(SCM attrib_smob);
SCM g_calcule_new_attrib_bounds (SCM attrib_smob, SCM scm_alignment,
				 SCM scm_angle, SCM scm_x, SCM scm_y);
SCM g_get_attrib_bounds(SCM attrib_smob);
SCM g_get_attrib_angle(SCM attrib_smob);
SCM g_get_attrib_value_by_attrib_name(SCM object_smob, SCM scm_attrib_name);
void g_init_object_smob(void);
SCM g_get_object_type(SCM object_smob);
SCM g_get_line_width(SCM object_smob);
void g_init_page_smob(void);
SCM g_get_page_filename(SCM page_smob);

/* o_arc_basic.c */
OBJECT *o_arc_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_arc_save(OBJECT *object);
void o_arc_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y);
void o_arc_print_solid(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int angle1, int angle2, int color, int arc_width, int length, int space, int origin_x, int origin_y);
void o_arc_print_dotted(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int angle1, int angle2, int color, int arc_width, int length, int space, int origin_x, int origin_y);
void o_arc_print_dashed(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int angle1, int angle2, int color, int arc_width, int length, int space, int origin_x, int origin_y);
void o_arc_print_center(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int angle1, int angle2, int color, int arc_width, int length, int space, int origin_x, int origin_y);
void o_arc_print_phantom(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int angle1, int angle2, int color, int arc_width, int length, int space, int origin_x, int origin_y);

/* o_attrib.c */
OBJECT *o_read_attribs(TOPLEVEL *toplevel,
		       OBJECT *object_to_get_attribs, 
		       TextBuffer *tb,
		       unsigned int release_ver, 
		       unsigned int fileformat_ver);
gchar *o_save_attribs(GList *attribs);

/* o_box_basic.c */
OBJECT *o_box_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_box_save(OBJECT *object);
void o_box_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y);
void o_box_print_solid(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_box_print_dotted(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_box_print_dashed(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_box_print_center(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_box_print_phantom(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_box_print_filled(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int fill_width, int angle1, int pitch1, int angle2, int pitch2, int origin_x, int origin_y);
void o_box_print_mesh(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int fill_width, int angle1, int pitch1, int angle2, int pitch2, int origin_x, int origin_y);
void o_box_print_hatch(TOPLEVEL *toplevel, FILE *fp, int x, int y, int width, int height, int color, int fill_width, int angle1, int pitch1, int angle2, int pitch2, int origin_x, int origin_y);

/* o_bus_basic.c */
OBJECT *o_bus_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_bus_save(OBJECT *object);
void o_bus_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y);

/* o_circle_basic.c */
OBJECT *o_circle_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_circle_save(OBJECT *object);
void o_circle_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y);
void o_circle_print_solid(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int circle_width, int length, int space, int origin_x, int origin_y);
void o_circle_print_dotted(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int circle_width, int length, int space, int origin_x, int origin_y);
void o_circle_print_dashed(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int circle_width, int length, int space, int origin_x, int origin_y);
void o_circle_print_center(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int circle_width, int length, int space, int origin_x, int origin_y);
void o_circle_print_phantom(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int circle_width, int length, int space, int origin_x, int origin_y);
void o_circle_print_filled(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int fill_width, int angle1, int pitch1, int angle2, int pitch2, int origin_x, int origin_y);
void o_circle_print_mesh(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int fill_width, int angle1, int pitch1, int angle2, int pitch2, int origin_x, int origin_y);
void o_circle_print_hatch(TOPLEVEL *toplevel, FILE *fp, int x, int y, int radius, int color, int fill_width, int angle1, int pitch1, int angle2, int pitch2, int origin_x, int origin_y);

/* o_complex_basic.c */
OBJECT *o_complex_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_complex_save(OBJECT *object);

/* o_line_basic.c */
OBJECT *o_line_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_line_save(OBJECT *object);
void o_line_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y);
void o_line_print_solid(TOPLEVEL *toplevel, FILE *fp, int x1, int y1, int x2, int y2, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_line_print_dotted(TOPLEVEL *toplevel, FILE *fp, int x1, int y1, int x2, int y2, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_line_print_dashed(TOPLEVEL *toplevel, FILE *fp, int x1, int y1, int x2, int y2, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_line_print_center(TOPLEVEL *toplevel, FILE *fp, int x1, int y1, int x2, int y2, int color, int line_width, int length, int space, int origin_x, int origin_y);
void o_line_print_phantom(TOPLEVEL *toplevel, FILE *fp, int x1, int y1, int x2, int y2, int color, int line_width, int length, int space, int origin_x, int origin_y);

/* o_net_basic.c */
OBJECT *o_net_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_net_save(OBJECT *object);
void o_net_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y);

/* o_picture.c */
OBJECT *o_picture_read(TOPLEVEL *toplevel, OBJECT *object_list,
		       const char *first_line,
		       TextBuffer *tb,
		       unsigned int release_ver,
		       unsigned int fileformat_ver);
char *o_picture_save(OBJECT *object);
void o_picture_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current,
		     int origin_x, int origin_y);

/* o_pin_basic.c */
OBJECT *o_pin_read(TOPLEVEL *toplevel, OBJECT *object_list, char buf[], unsigned int release_ver, unsigned int fileformat_ver);
char *o_pin_save(OBJECT *object);
void o_pin_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y);

/* o_text_basic.c */
OBJECT *o_text_read(TOPLEVEL *toplevel,
		    OBJECT *object_list, 
		    const char *first_line,
		    TextBuffer *tb,
		    unsigned int release_ver,
		    unsigned int fileformat_ver);
char *o_text_save(OBJECT *object);
void o_text_print_text_width(FILE *fp, char *output_string);
void o_text_print_text_height(FILE *fp, int size);
void o_text_print_text_height_full(FILE *fp, char *string, int size);
void o_text_print_text_string(FILE *fp, char *string, int unicode_count, gunichar *unicode_table);
void o_text_print(TOPLEVEL *toplevel, FILE *fp, OBJECT *o_current, int origin_x, int origin_y, int unicode_count, gunichar *unicode_table);

/* s_clib.c */
void s_clib_init (void);

/* s_color.c */
void s_color_init(void);
char *s_color_ps_string(int color);

/* s_encoding.c */
gchar* s_encoding_base64_encode (gchar* src, guint srclen, guint* dstlenp, gboolean strict);
gchar* s_encoding_base64_decode (gchar* src, guint srclen, guint* dstlenp);

/* s_textbuffer.c */
TextBuffer *s_textbuffer_new (gchar *data, const gint size);
TextBuffer *s_textbuffer_free (TextBuffer *tb);
void s_textbuffer_seek (TextBuffer *tb, const gint offset);
gchar *s_textbuffer_next (TextBuffer *tb, const gsize count);
gchar *s_textbuffer_next_line (TextBuffer *tb);