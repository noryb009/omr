/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 ******************************************************************************/

#ifndef PORT_INCL
#define PORT_INCL

#include "omrport.h"

namespace TR {

class PortLibrary
   {
   public:
   static void init()
      {
      // TODO: move this to thread-only
      intptr_t rc = 0;//omrthread_attach_ex(NULL, J9THREAD_ATTR_DEFAULT);
      if (rc != 0) {
         return;
      }

      // TODO: use rc
      rc = omrport_init_library(&_compilerPortLibrary, sizeof(OMRPortLibrary));
      _initialized = true;
      }

   // TODO: call
   static void destruct()
      {
      _compilerPortLibrary.port_shutdown_library(&_compilerPortLibrary);
      omrthread_detach(NULL);
      }

   static OMRPortLibrary *getPortLibrary()
      {
      if(!_initialized)
         init();
      return &_compilerPortLibrary;
      }

   private:
   // TODO: non-static?
   static bool _initialized;
   static OMRPortLibrary _compilerPortLibrary;
   };

}

#endif
