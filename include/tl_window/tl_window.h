#pragma once

#include <tl_base/tl_common.h>
#include <tl_base/tl_getter_setter.h>
#include <tl_base/tl_pointer.h>

#include <string>

namespace tl { namespace gfx {

	//-------------------------------------------------------------------------

  class window_params
  {
    public:
      using this_type = window_params;

    public:
      window_params();

			TLOC_DECL_PARAM_VAR(int, width, m_width);
			TLOC_DECL_PARAM_VAR(int, height, m_height);

			TLOC_DECL_PARAM_VAR(int, x_pos, m_x_pos);
			TLOC_DECL_PARAM_VAR(int, y_pos, m_y_pos);

			TLOC_DECL_PARAM_VAR_REF(std::string, name, m_name);
  };

	//-------------------------------------------------------------------------

  class window
  {
		public:
      using id = uint;

    public:
      window(const window_params& a_params);
      ~window();

      void make_context_current();
			void swap_buffers();
      id   get_id() const;

    private:
      TLOC_POINTER_IMPL(window_impl) m_impl;
  };

	TLOC_TYPEDEF_SHARED_PTR(window);

};};

#include <tl_base/tl_exception.h>
namespace tl { namespace except {

  TLOC_EXCEPTION_DEFINE(window_initialization);

};};


