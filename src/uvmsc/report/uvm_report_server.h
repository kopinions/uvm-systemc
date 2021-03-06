//----------------------------------------------------------------------------
//   Copyright 2007-2010 Mentor Graphics Corporation
//   Copyright 2007-2011 Cadence Design Systems, Inc. 
//   Copyright 2010 Synopsys, Inc.
//   Copyright 2014 NVIDIA Corporation
//   Copyright 2016 NXP B.V.
//   Copyright 2018 Intel Corp.
//   All Rights Reserved Worldwide
//
//   Licensed under the Apache License, Version 2.0 (the
//   "License"); you may not use this file except in
//   compliance with the License.  You may obtain a copy of
//   the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in
//   writing, software distributed under the License is
//   distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//   CONDITIONS OF ANY KIND, either express or implied.  See
//   the License for the specific language governing
//   permissions and limitations under the License.
//----------------------------------------------------------------------------

#ifndef UVM_REPORT_SERVER_H_
#define UVM_REPORT_SERVER_H_

#include "uvmsc/base/uvm_object.h"

namespace uvm {

// forward class declarations
class uvm_default_report_server;
class uvm_tr_database;
class uvm_report_message;

//----------------------------------------------------------------------------
// CLASS: uvm_report_server
//
//! The class uvm_report_server is a global server that processes all of the reports
//! generated by an uvm_report_handler.
//!
//! The uvm_report_server is an abstract class which declares many of its methods
//! as pure virtual. The UVM uses the class uvm_default_report_server
//! as its default report server implementation.
//----------------------------------------------------------------------------

class uvm_report_server : public uvm_object
{
 public:

  //--------------------------------------------------------------------------
  // UVM Standard LRM API below
  //--------------------------------------------------------------------------

  uvm_report_server( const std::string& name = "base" );

  const std::string get_type_name() const;

  virtual void set_max_quit_count( int count, bool overridable = true ) = 0;

  virtual int get_max_quit_count() const = 0;

  virtual void set_quit_count( int quit_count ) = 0;

  virtual int get_quit_count() const = 0;

  virtual void set_severity_count( uvm_severity severity, int count ) = 0;

  virtual int get_severity_count( uvm_severity severity ) const = 0;

  virtual void set_id_count( const std::string& id, int count ) = 0;

  virtual int get_id_count( const std::string& id ) const = 0;

  virtual void get_id_set( std::vector<std::string>& q ) const = 0;

  virtual void get_severity_set( std::vector<uvm_severity>& q ) const = 0;

//TODO transaction recording
//  virtual void set_message_database( uvm_tr_database* database ) = 0;

//  virtual uvm_tr_database* get_message_database() const = 0;

  void do_copy( const uvm_object& rhs );

  virtual void process_report_message( uvm_report_message* report_message ) = 0;

  virtual void execute_report_message( uvm_report_message* report_message,
                                       const std::string& composed_message ) = 0;

  virtual std::string compose_report_message( uvm_report_message* report_message,
                                              const std::string& report_object_name = "") const = 0;

  virtual void report_summarize( UVM_FILE file = 0 ) const = 0;

  static void set_server( uvm_report_server* server );

  static uvm_report_server* get_server();

}; // class uvm_report_server

} // namespace uvm

#endif // UVM_REPORT_SERVER_H_

