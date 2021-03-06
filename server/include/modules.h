#ifndef _MODULES_H
#define _MODULES_H
/*
 * This file is distributed as part of the SkySQL Gateway.  It is free
 * software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation,
 * version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Copyright SkySQL Ab 2013
 */
#include <dcb.h>
#include <modinfo.h>

/**
 * @file modules.h	Utilities for loading modules
 *
 * The module interface used within the gateway
 *
 * @verbatim
 * Revision History
 *
 * Date		Who		Description
 * 13/06/13	Mark Riddoch	Initial implementation
 * 08/07/13	Mark Riddoch	Addition of monitor modules
 * 29/05/14	Mark Riddoch	Addition of filter modules
 * @endverbatim
 */

typedef struct modules {
	char	*module;	/**< The name of the module */
	char	*type;		/**< The module type */
	char	*version;	/**< Module version */
	void	*handle;	/**< The handle returned by dlopen */
	void	*modobj;	/**< The module "object" this is the set of entry points */
	MODULE_INFO
		*info;		/**< The module information */
	struct	modules
		*next;		/**< Next module in the linked list */
} MODULES;

/**
 * Module types
 */
#define	MODULE_PROTOCOL	"Protocol"	/**< A protocol module type */
#define	MODULE_ROUTER	"Router"	/**< A router module type */
#define	MODULE_MONITOR	"Monitor"	/**< A database monitor module type */
#define	MODULE_FILTER	"Filter"	/**< A filter module type */


extern	void 	*load_module(const char *module, const char *type);
extern	void	unload_module(const char *module);
extern	void	printModules();
extern	void	dprintAllModules(DCB *);
char*     get_maxscale_home(void);

#endif
