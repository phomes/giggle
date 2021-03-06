/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2007 Imendio AB
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GIGGLE_FILE_LIST_H__
#define __GIGGLE_FILE_LIST_H__

#include <gtk/gtk.h>

#include "libgiggle/giggle-revision.h"

G_BEGIN_DECLS

#define GIGGLE_TYPE_FILE_LIST            (giggle_file_list_get_type ())
#define GIGGLE_FILE_LIST(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIGGLE_TYPE_FILE_LIST, GiggleFileList))
#define GIGGLE_FILE_LIST_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIGGLE_TYPE_FILE_LIST, GiggleFileListClass))
#define GIGGLE_IS_FILE_LIST(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIGGLE_TYPE_FILE_LIST))
#define GIGGLE_IS_FILE_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIGGLE_TYPE_FILE_LIST))
#define GIGGLE_FILE_LIST_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIGGLE_TYPE_FILE_LIST, GiggleFileListClass))

typedef struct _GiggleFileList      GiggleFileList;
typedef struct _GiggleFileListClass GiggleFileListClass;

struct _GiggleFileList {
	GtkTreeView parent_instance;
};

struct _GiggleFileListClass {
	GtkTreeViewClass parent_class;

	void (* path_selected) (GiggleFileList *list, const gchar *path);
	void (* project_loaded) (GiggleFileList *list);
	void (* status_changed) (GiggleFileList *list);
};

GType              giggle_file_list_get_type            (void);
GtkWidget *        giggle_file_list_new                 (void);

gboolean           giggle_file_list_get_show_all        (GiggleFileList *list);
void               giggle_file_list_set_show_all        (GiggleFileList *list,
							 gboolean        show_all);

void               giggle_file_list_highlight_revisions (GiggleFileList *list,
							 GiggleRevision *from,
							 GiggleRevision *to);

GList *            giggle_file_list_get_selection       (GiggleFileList *list);
void		   giggle_file_list_select              (GiggleFileList *list,
							 const char     *path);

G_END_DECLS

#endif /* __GIGGLE_FILE_LIST_H__ */
