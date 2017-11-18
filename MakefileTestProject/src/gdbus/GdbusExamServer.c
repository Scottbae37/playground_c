/*
 * GdbusExamServer.c
 *
 *  Created on: Sep 25, 2017
 *      Author: scottbae37
 */

#include "autogen.h"
#include <gio/gio.h>
#include <stdio.h>
nsBjsV1Animal1 * serverObj;
static void on_name_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data)
{
	printf("on_name_acquired() called\n");
	serverObj  = ns_bjs_v1_animal1_skeleton_new();
	GError *error;
	gchar* objPath = "/bjs/v1/Animal1";
	error = NULL;
	gboolean result = g_dbus_interface_skeleton_export (G_DBUS_INTERFACE_SKELETON (serverObj), connection, objPath, &error);
	if(result == TRUE)
		printf("skeleton object is successfully exported OK!!!!\n");
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.1);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.2);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.3);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.4);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.5);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.6);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.7);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.8);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 1.9);
	ns_bjs_v1_animal1_emit_jumped(serverObj, 2.0);
	printf("Sent Signal !\n");

	GVariantBuilder *builder = g_variant_builder_new(G_VARIANT_TYPE_VARDICT);
}

#if 1
int main(){

	printf("GDBus Server example\n");
	gchar* busName= "bjs.wellknown.name1";
	GError* error;
	guint result = -1;
	result = g_bus_own_name(
			G_BUS_TYPE_SESSION,
			busName,
			G_BUS_NAME_OWNER_FLAGS_REPLACE,
			NULL,
			on_name_acquired,
			NULL,
			NULL,
			NULL);
	if(result == TRUE)
		printf("result %d is OK, TRUE\n", result);


	printf("GDBus Server loop started\n");
	GMainLoop *loop;
	loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);
	printf("GDBus Server loop end\n");
	return 0;
}
#endif
