#include <libgeda.h>
#include <version.h>

static const gchar* strings[] =
{
  "one",
  "one\ntwo",
  "one\ntwo\nthree",
  "one\ntwo\nthree\nfour",
  "one\ntwo\nthree\nfour\nfive",
  "one\ntwo\nthree\nfour\nfive\nsix",
  "one\ntwo\nthree\nfour\nfive\nsix\nseven",
  "one\ntwo\nthree\nfour\nfive\nsix\nseven\neight",
};

#define STRINGS_COUNT (sizeof (strings) / sizeof (gchar*))

void
check_construction ()
{
  gint count;
  GedaToplevel *toplevel = s_toplevel_new ();

  for (count = 0; count < 1000; count++) {
    gint x = g_test_rand_int ();
    gint y = g_test_rand_int ();
    gint alignment = g_test_rand_int_range (0, 9);
    gint angle = geda_angle_normalize (geda_angle_make_ortho (g_test_rand_int ()));
    gint color = g_test_rand_int_range (0, MAX_COLORS - 1);
    gint show_name_value = g_test_rand_int_range (0, 3);
    gint size = g_test_rand_int_range (MINIMUM_TEXT_SIZE, G_MAXINT);
    const gchar *string = strings[g_test_rand_int_range (0, STRINGS_COUNT)];
    gboolean visible = g_test_rand_bit ();

    GedaObject *object0 = geda_text_object_new (toplevel,
                                                color,
                                                x,
                                                y,
                                                alignment,
                                                angle,
                                                string,
                                                size,
                                                visible,
                                                show_name_value);

    g_assert (object0 != NULL);
    g_assert_cmpint (OBJ_TEXT, ==, object0->type);

    g_assert_cmpint (x, ==, geda_text_object_get_x (object0));
    g_assert_cmpint (y, ==, geda_text_object_get_y (object0));
    g_assert_cmpint (alignment, ==, geda_text_object_get_alignment (object0));
    g_assert_cmpint (angle, ==, geda_text_object_get_angle (object0));
    g_assert_cmpint (size, ==, geda_text_object_get_size (object0));
    g_assert_cmpint (color, ==, geda_object_get_color (object0));
    g_assert_cmpint (visible, ==, geda_object_get_visible (object0));
    g_assert_cmpstr (string, ==, geda_text_object_get_string (object0));

    GedaObject *object1 = geda_text_object_copy (toplevel, object0);

    g_assert (object1 != NULL);
    g_assert (object1 != object0);
    g_assert_cmpint (OBJ_TEXT, ==, object1->type);

    s_delete_object (toplevel, object0);

    g_assert_cmpint (x, ==, geda_text_object_get_x (object1));
    g_assert_cmpint (y, ==, geda_text_object_get_y (object1));
    g_assert_cmpint (alignment, ==, geda_text_object_get_alignment (object1));
    g_assert_cmpint (angle, ==, geda_text_object_get_angle (object1));
    g_assert_cmpint (size, ==, geda_text_object_get_size (object1));
    g_assert_cmpint (color, ==, geda_object_get_color (object1));
    g_assert_cmpint (visible, ==, geda_object_get_visible (object1));
    g_assert_cmpstr (string, ==, geda_text_object_get_string (object1));

    s_delete_object (toplevel, object1);
  }

  s_toplevel_delete (toplevel);
}

void
check_accessors ()
{
  gint count;
  GedaToplevel *toplevel = s_toplevel_new ();

  for (count = 0; count < 1000; count++) {
    gint x = g_test_rand_int ();
    gint y = g_test_rand_int ();
    gint alignment = g_test_rand_int_range (0, 9);
    gint angle = geda_angle_normalize (geda_angle_make_ortho (g_test_rand_int ()));
    gint color = g_test_rand_int_range (0, MAX_COLORS - 1);
    gint show_name_value = g_test_rand_int_range (0, 3);
    gint size = g_test_rand_int_range (MINIMUM_TEXT_SIZE, G_MAXINT);
    const gchar *string = strings[g_test_rand_int_range (0, STRINGS_COUNT)];
    gboolean visible = g_test_rand_bit ();

    GedaObject *object0 = geda_text_object_new (toplevel,
                                                color,
                                                x,
                                                y,
                                                alignment,
                                                angle,
                                                string,
                                                size,
                                                visible,
                                                show_name_value);

    g_assert (object0 != NULL);
    g_assert_cmpint (OBJ_TEXT, ==, object0->type);

    x = g_test_rand_int ();
    y = g_test_rand_int ();
    alignment = g_test_rand_int_range (0, 9);
    angle = geda_angle_normalize (geda_angle_make_ortho (g_test_rand_int ()));
    color = g_test_rand_int_range (0, MAX_COLORS - 1);
    show_name_value = g_test_rand_int_range (0, 3);
    size = g_test_rand_int_range (0, G_MAXINT);
    string = strings[g_test_rand_int_range (0, STRINGS_COUNT)];
    visible = g_test_rand_bit ();

    geda_text_object_set_x (object0, x);
    geda_text_object_set_y (object0, y);
    geda_text_object_set_alignment (object0, alignment);
    geda_text_object_set_angle (object0, angle);
    geda_text_object_set_size (object0, size);
    o_set_color (toplevel, object0, color);
    o_set_visibility (toplevel, object0, visible);
    o_text_set_string (toplevel, object0, string);

    g_assert_cmpint (x, ==, geda_text_object_get_x (object0));
    g_assert_cmpint (y, ==, geda_text_object_get_y (object0));
    g_assert_cmpint (alignment, ==, geda_text_object_get_alignment (object0));
    g_assert_cmpint (angle, ==, geda_text_object_get_angle (object0));
    g_assert_cmpint (size, ==, geda_text_object_get_size (object0));
    g_assert_cmpint (color, ==, geda_object_get_color (object0));
    g_assert_cmpint (visible, ==, geda_object_get_visible (object0));
    g_assert_cmpstr (string, ==, geda_text_object_get_string (object0));

    gint temp_x;
    gint temp_y;
    geda_text_object_get_position (object0, &temp_x, &temp_y);
    g_assert_cmpint (x, ==, temp_x);
    g_assert_cmpint (y, ==, temp_y);

    s_delete_object (toplevel, object0);
  }

  s_toplevel_delete (toplevel);
}

void
check_serialization ()
{
  gint count;
  gint converted;
  GedaToplevel *toplevel = s_toplevel_new ();
  guint version;

  converted = sscanf (PACKAGE_DATE_VERSION, "%u", &version);
  g_assert_cmpuint (converted, ==, 1);

  for (count = 0; count < 1000; count++) {
    gint x = g_test_rand_int ();
    gint y = g_test_rand_int ();
    gint alignment = g_test_rand_int_range (0, 9);
    gint angle = geda_angle_normalize (geda_angle_make_ortho (g_test_rand_int ()));
    gint color = g_test_rand_int_range (0, MAX_COLORS - 1);
    gint show_name_value = g_test_rand_int_range (0, 3);
    gint size = g_test_rand_int_range (MINIMUM_TEXT_SIZE, G_MAXINT);
    const gchar *string = strings[g_test_rand_int_range (0, STRINGS_COUNT)];
    gboolean visible = g_test_rand_bit ();

    GedaObject *object0 = geda_text_object_new (toplevel,
                                                color,
                                                x,
                                                y,
                                                alignment,
                                                angle,
                                                string,
                                                size,
                                                visible,
                                                show_name_value);

    g_assert (object0 != NULL);

    gchar *buffer0 = geda_text_object_to_buffer (object0);
    s_delete_object (toplevel, object0);
    g_assert (buffer0 != NULL);

    TextBuffer *tb = s_textbuffer_new (buffer0, -1);
    gchar *line = s_textbuffer_next_line (tb);

    GedaObject *object1 = o_text_read (toplevel,
                                      line,
                                      tb,
                                      version,
                                      FILEFORMAT_VERSION,
                                      NULL);

    g_assert (object1 != NULL);
    s_textbuffer_free (tb);

    g_assert_cmpint (x, ==, geda_text_object_get_x (object1));
    g_assert_cmpint (y, ==, geda_text_object_get_y (object1));
    g_assert_cmpint (alignment, ==, geda_text_object_get_alignment (object1));
    g_assert_cmpint (angle, ==, geda_text_object_get_angle (object1));
    g_assert_cmpint (size, ==, geda_text_object_get_size (object1));
    g_assert_cmpint (color, ==, geda_object_get_color (object1));
    g_assert_cmpint (visible, ==, geda_object_get_visible (object1));
    g_assert_cmpstr (string, ==, geda_text_object_get_string (object1));

    gchar *buffer1 = geda_text_object_to_buffer (object1);
    s_delete_object (toplevel, object1);
    g_assert (buffer1 != NULL);

    g_assert_cmpstr (buffer0, ==, buffer1);
    g_free (buffer0);
    g_free (buffer1);
  }

  s_toplevel_delete (toplevel);
}

int
main (int argc, char *argv[])
{
  g_test_init (&argc, &argv, NULL);

  g_test_add_func ("/geda/libgeda/text_object/construction",
                   check_construction);

  g_test_add_func ("/geda/libgeda/text_object/check_accessors",
                   check_accessors);

  g_test_add_func ("/geda/libgeda/text_object/serialization",
                   check_serialization);

  return g_test_run ();
}
