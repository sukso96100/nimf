/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/*
 * nimf-service.h
 * This file is part of Nimf.
 *
 * Copyright (C) 2017 Hodong Kim <cogniti@gmail.com>
 *
 * Nimf is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Nimf is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program;  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __NIMF_SERVICE_H__
#define __NIMF_SERVICE_H__

#if !defined (__NIMF_H_INSIDE__) && !defined (NIMF_COMPILATION)
#error "Only <nimf.h> can be included directly."
#endif

#include <glib-object.h>
#include "nimf-server.h"

G_BEGIN_DECLS

#define NIMF_TYPE_SERVICE             (nimf_service_get_type ())
#define NIMF_SERVICE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), NIMF_TYPE_SERVICE, NimfService))
#define NIMF_SERVICE_CLASS(class)     (G_TYPE_CHECK_CLASS_CAST ((class), NIMF_TYPE_SERVICE, NimfServiceClass))
#define NIMF_IS_SERVICE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NIMF_TYPE_SERVICE))
#define NIMF_IS_SERVICE_CLASS(class)  (G_TYPE_CHECK_CLASS_TYPE ((class), NIMF_TYPE_SERVICE))
#define NIMF_SERVICE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), NIMF_TYPE_SERVICE, NimfServiceClass))

typedef struct _NimfService       NimfService;
typedef struct _NimfServiceClass  NimfServiceClass;

struct _NimfService
{
  GObject parent_instance;
  NimfServer *server;
};

struct _NimfServiceClass
{
  /*< private >*/
  GObjectClass parent_class;

  /*< public >*/
  /* Virtual functions */
  const gchar * (* get_id)           (NimfService *service);
  void          (* start)            (NimfService *service);
  void          (* stop)             (NimfService *service);
  void          (* set_engine_by_id) (NimfService *service,
                                      const gchar *engine_id);
};

GType        nimf_service_get_type         (void) G_GNUC_CONST;
void         nimf_service_start            (NimfService *service);
void         nimf_service_stop             (NimfService *service);
const gchar *nimf_service_get_id           (NimfService *service);
void         nimf_service_set_engine_by_id (NimfService *service,
                                            const gchar *engine_id);

G_END_DECLS

#endif /* __NIMF_SERVICE_H__ */
