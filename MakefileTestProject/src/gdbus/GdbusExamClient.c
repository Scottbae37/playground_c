/*
 * GdbusExamClient.c
 *
 *  Created on: Sep 25, 2017
 *      Author: scottbae37
 */

#include "autogen.h"
#include <gio/gio.h>
#include <stdio.h>

void myJumpedCallback(nsBjsV1Animal1 *object, gdouble arg_height){
	printf("myJumpedCallback() is called with argument %f\n", arg_height);
}

void my_sigCallback(nsBjsV1Animal1 *object, guint arg_id,  guint arg_number,  GVariant *arg_map){
	printf("my_sigCallback() is called with argument id:%u, num:%u \n", arg_id, arg_number);
}
#if 0
int main(){
	GMainLoop *loop;

	printf("GDBus Client example\n");
	gchar* busName= "bjs.wellknown.name1";
	gchar* objPath = "/bjs/v1/Animal1";
	GError* error;
	nsBjsV1Animal1* proxyObj = ns_bjs_v1_animal1_proxy_new_for_bus_sync(
			G_BUS_TYPE_SESSION,
			G_BUS_NAME_OWNER_FLAGS_NONE,
			busName,
			objPath,
			NULL,
			&error
			);

	nsBjsV1Animal1Iface* interface;
	interface = NS_BJS_V1_ANIMAL1_GET_IFACE(proxyObj);
	interface->jumped = myJumpedCallback;
	interface->my_sig = my_sigCallback;

	printf("GDBus Client loop started\n");
	loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);
	printf("GDBus Client loop end\n");

	return 0;
}
#endif
