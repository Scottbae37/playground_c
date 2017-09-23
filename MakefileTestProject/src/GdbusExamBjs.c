/*
 ============================================================================
 Name        : LinuxTestProject.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <glib.h>
#include <glib/gprintf.h>

int main(void) {
	gchar * str;
	str = g_malloc(128);
	g_sprintf(str, "Glib Test");
	g_printf("%s\n", str);
	g_free(str);
	return 0;
}
