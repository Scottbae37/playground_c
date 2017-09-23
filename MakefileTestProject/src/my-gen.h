/*
 * Generated by gdbus-codegen 2.50.3. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __MY_GEN_H__
#define __MY_GEN_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for com.bjs.ObjectManager.Animal */

#define BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL (bjs_com_bjs_object_manager_animal_get_type ())
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL, BjsComBjsObjectManagerAnimal))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_ANIMAL(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL))
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL, BjsComBjsObjectManagerAnimalIface))

struct _BjsComBjsObjectManagerAnimal;
typedef struct _BjsComBjsObjectManagerAnimal BjsComBjsObjectManagerAnimal;
typedef struct _BjsComBjsObjectManagerAnimalIface BjsComBjsObjectManagerAnimalIface;

struct _BjsComBjsObjectManagerAnimalIface
{
  GTypeInterface parent_iface;



  gboolean (*handle_poke) (
    BjsComBjsObjectManagerAnimal *object,
    GDBusMethodInvocation *invocation,
    gboolean arg_make_sad,
    gboolean arg_make_happy);

  const gchar * (*get_mood) (BjsComBjsObjectManagerAnimal *object);

  void (*jumped) (
    BjsComBjsObjectManagerAnimal *object,
    gdouble arg_height);

};

GType bjs_com_bjs_object_manager_animal_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *bjs_com_bjs_object_manager_animal_interface_info (void);
guint bjs_com_bjs_object_manager_animal_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void bjs_com_bjs_object_manager_animal_complete_poke (
    BjsComBjsObjectManagerAnimal *object,
    GDBusMethodInvocation *invocation);



/* D-Bus signal emissions functions: */
void bjs_com_bjs_object_manager_animal_emit_jumped (
    BjsComBjsObjectManagerAnimal *object,
    gdouble arg_height);



/* D-Bus method calls: */
void bjs_com_bjs_object_manager_animal_call_poke (
    BjsComBjsObjectManagerAnimal *proxy,
    gboolean arg_make_sad,
    gboolean arg_make_happy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean bjs_com_bjs_object_manager_animal_call_poke_finish (
    BjsComBjsObjectManagerAnimal *proxy,
    GAsyncResult *res,
    GError **error);

gboolean bjs_com_bjs_object_manager_animal_call_poke_sync (
    BjsComBjsObjectManagerAnimal *proxy,
    gboolean arg_make_sad,
    gboolean arg_make_happy,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
const gchar *bjs_com_bjs_object_manager_animal_get_mood (BjsComBjsObjectManagerAnimal *object);
gchar *bjs_com_bjs_object_manager_animal_dup_mood (BjsComBjsObjectManagerAnimal *object);
void bjs_com_bjs_object_manager_animal_set_mood (BjsComBjsObjectManagerAnimal *object, const gchar *value);


/* ---- */

#define BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY (bjs_com_bjs_object_manager_animal_proxy_get_type ())
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY, BjsComBjsObjectManagerAnimalProxy))
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY, BjsComBjsObjectManagerAnimalProxyClass))
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY, BjsComBjsObjectManagerAnimalProxyClass))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_PROXY))

typedef struct _BjsComBjsObjectManagerAnimalProxy BjsComBjsObjectManagerAnimalProxy;
typedef struct _BjsComBjsObjectManagerAnimalProxyClass BjsComBjsObjectManagerAnimalProxyClass;
typedef struct _BjsComBjsObjectManagerAnimalProxyPrivate BjsComBjsObjectManagerAnimalProxyPrivate;

struct _BjsComBjsObjectManagerAnimalProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  BjsComBjsObjectManagerAnimalProxyPrivate *priv;
};

struct _BjsComBjsObjectManagerAnimalProxyClass
{
  GDBusProxyClass parent_class;
};

GType bjs_com_bjs_object_manager_animal_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BjsComBjsObjectManagerAnimalProxy, g_object_unref)
#endif

void bjs_com_bjs_object_manager_animal_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
BjsComBjsObjectManagerAnimal *bjs_com_bjs_object_manager_animal_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
BjsComBjsObjectManagerAnimal *bjs_com_bjs_object_manager_animal_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void bjs_com_bjs_object_manager_animal_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
BjsComBjsObjectManagerAnimal *bjs_com_bjs_object_manager_animal_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
BjsComBjsObjectManagerAnimal *bjs_com_bjs_object_manager_animal_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON (bjs_com_bjs_object_manager_animal_skeleton_get_type ())
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON, BjsComBjsObjectManagerAnimalSkeleton))
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON, BjsComBjsObjectManagerAnimalSkeletonClass))
#define BJS_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON, BjsComBjsObjectManagerAnimalSkeletonClass))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_ANIMAL_SKELETON))

typedef struct _BjsComBjsObjectManagerAnimalSkeleton BjsComBjsObjectManagerAnimalSkeleton;
typedef struct _BjsComBjsObjectManagerAnimalSkeletonClass BjsComBjsObjectManagerAnimalSkeletonClass;
typedef struct _BjsComBjsObjectManagerAnimalSkeletonPrivate BjsComBjsObjectManagerAnimalSkeletonPrivate;

struct _BjsComBjsObjectManagerAnimalSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  BjsComBjsObjectManagerAnimalSkeletonPrivate *priv;
};

struct _BjsComBjsObjectManagerAnimalSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType bjs_com_bjs_object_manager_animal_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BjsComBjsObjectManagerAnimalSkeleton, g_object_unref)
#endif

BjsComBjsObjectManagerAnimal *bjs_com_bjs_object_manager_animal_skeleton_new (void);


/* ------------------------------------------------------------------------ */
/* Declarations for com.bjs.ObjectManager.Cat */

#define BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT (bjs_com_bjs_object_manager_cat_get_type ())
#define BJS_COM_BJS_OBJECT_MANAGER_CAT(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT, BjsComBjsObjectManagerCat))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_CAT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT))
#define BJS_COM_BJS_OBJECT_MANAGER_CAT_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT, BjsComBjsObjectManagerCatIface))

struct _BjsComBjsObjectManagerCat;
typedef struct _BjsComBjsObjectManagerCat BjsComBjsObjectManagerCat;
typedef struct _BjsComBjsObjectManagerCatIface BjsComBjsObjectManagerCatIface;

struct _BjsComBjsObjectManagerCatIface
{
  GTypeInterface parent_iface;
};

GType bjs_com_bjs_object_manager_cat_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *bjs_com_bjs_object_manager_cat_interface_info (void);
guint bjs_com_bjs_object_manager_cat_override_properties (GObjectClass *klass, guint property_id_begin);


/* ---- */

#define BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_PROXY (bjs_com_bjs_object_manager_cat_proxy_get_type ())
#define BJS_COM_BJS_OBJECT_MANAGER_CAT_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_PROXY, BjsComBjsObjectManagerCatProxy))
#define BJS_COM_BJS_OBJECT_MANAGER_CAT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_PROXY, BjsComBjsObjectManagerCatProxyClass))
#define BJS_COM_BJS_OBJECT_MANAGER_CAT_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_PROXY, BjsComBjsObjectManagerCatProxyClass))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_CAT_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_PROXY))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_CAT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_PROXY))

typedef struct _BjsComBjsObjectManagerCatProxy BjsComBjsObjectManagerCatProxy;
typedef struct _BjsComBjsObjectManagerCatProxyClass BjsComBjsObjectManagerCatProxyClass;
typedef struct _BjsComBjsObjectManagerCatProxyPrivate BjsComBjsObjectManagerCatProxyPrivate;

struct _BjsComBjsObjectManagerCatProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  BjsComBjsObjectManagerCatProxyPrivate *priv;
};

struct _BjsComBjsObjectManagerCatProxyClass
{
  GDBusProxyClass parent_class;
};

GType bjs_com_bjs_object_manager_cat_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BjsComBjsObjectManagerCatProxy, g_object_unref)
#endif

void bjs_com_bjs_object_manager_cat_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
BjsComBjsObjectManagerCat *bjs_com_bjs_object_manager_cat_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
BjsComBjsObjectManagerCat *bjs_com_bjs_object_manager_cat_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void bjs_com_bjs_object_manager_cat_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
BjsComBjsObjectManagerCat *bjs_com_bjs_object_manager_cat_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
BjsComBjsObjectManagerCat *bjs_com_bjs_object_manager_cat_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_SKELETON (bjs_com_bjs_object_manager_cat_skeleton_get_type ())
#define BJS_COM_BJS_OBJECT_MANAGER_CAT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_SKELETON, BjsComBjsObjectManagerCatSkeleton))
#define BJS_COM_BJS_OBJECT_MANAGER_CAT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_SKELETON, BjsComBjsObjectManagerCatSkeletonClass))
#define BJS_COM_BJS_OBJECT_MANAGER_CAT_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_SKELETON, BjsComBjsObjectManagerCatSkeletonClass))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_CAT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_SKELETON))
#define BJS_IS_COM_BJS_OBJECT_MANAGER_CAT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BJS_TYPE_COM_BJS_OBJECT_MANAGER_CAT_SKELETON))

typedef struct _BjsComBjsObjectManagerCatSkeleton BjsComBjsObjectManagerCatSkeleton;
typedef struct _BjsComBjsObjectManagerCatSkeletonClass BjsComBjsObjectManagerCatSkeletonClass;
typedef struct _BjsComBjsObjectManagerCatSkeletonPrivate BjsComBjsObjectManagerCatSkeletonPrivate;

struct _BjsComBjsObjectManagerCatSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  BjsComBjsObjectManagerCatSkeletonPrivate *priv;
};

struct _BjsComBjsObjectManagerCatSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType bjs_com_bjs_object_manager_cat_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BjsComBjsObjectManagerCatSkeleton, g_object_unref)
#endif

BjsComBjsObjectManagerCat *bjs_com_bjs_object_manager_cat_skeleton_new (void);


G_END_DECLS

#endif /* __MY_GEN_H__ */
