// -*- C++ -*-
// $Id$

#include "dds4ccm/impl/DataReaderStateListener_T.h"
#include "dds4ccm/impl/DataWriterListener_T.h"
#include "dds4ccm/impl/StateListenerControl_T.h"
#include "dds4ccm/impl/PortStatusListener_T.h"

#include "dds4ccm/impl/Log_Macros.h"

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED, DDS4CCM_Vendor VENDOR_TYPE>
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::DDS_StateListen_T (void) :
  data_control_ (new CCM_DDS_StateListenerControl_T
    < ::CCM_DDS::CCM_StateListenerControl, CCM_TYPE> ())
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED, DDS4CCM_Vendor VENDOR_TYPE>
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::~DDS_StateListen_T (void)
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED, DDS4CCM_Vendor VENDOR_TYPE>
bool
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::configuration_complete (
  typename CCM_TYPE::base_type::_ptr_type component,
  ::DDS::Topic_ptr topic,
  ::DDS::Subscriber_ptr subscriber,
  const char* library_name,
  const char* profile_name)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::configuration_complete");

  if (DDSSubscriberBase_type::configuration_complete (
            component,
            topic,
            subscriber,
            library_name,
            profile_name))
    {
      StateListenerControl_type *dds_slc = dynamic_cast < StateListenerControl_type * >
        (this->data_control_.in ());
      if (dds_slc)
        {
          dds_slc->_set_component (component);
          return true;
        }
      else
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO
                        ACE_TEXT ("DDS_StateListen_T::configuration_complete - ")
                        ACE_TEXT ("Unable to cast Data control.\n")));
          return false;
        }
    }
  return false;
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED, DDS4CCM_Vendor VENDOR_TYPE>
void
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::activate (
  typename CCM_TYPE::statelistener_type::_ptr_type listener,
  ::CCM_DDS::PortStatusListener_ptr status,
  ACE_Reactor* reactor)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::activate");

  if (::CORBA::is_nil (this->listener_.in ()))
    {
      ACE_NEW_THROW_EX (this->listener_,
                        DataReaderStateListener_type (
                          listener,
                          status,
                          this->data_control_.in (),
                          reactor,
                          &this->condition_manager_),
                        CORBA::NO_MEMORY ());
    }
  ::DDS::ReturnCode_t const retcode = this->data_reader_.set_listener (
                              this->listener_.in (),
                              DataReaderStateListener_type::get_mask (listener));
  if (retcode != DDS::RETCODE_OK)
    {
      DDS4CCM_ERROR (1, (LM_ERROR, CLINFO
                    "DDS_StateListen_T::activate - "
                    "Error during set_listener - <%C>\n",
                    ::CIAO::DDS4CCM::translate_retcode (retcode)));
    }
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED, DDS4CCM_Vendor VENDOR_TYPE>
void
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::remove (
  ::DDS::Subscriber_ptr subscriber)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::remove");

  StateListenerControl_type *dds_slc = dynamic_cast < StateListenerControl_type * >
    (this->data_control_.in ());
  if (dds_slc)
    {
      dds_slc->_set_component (CCM_TYPE::base_type::_nil ());
    }
  else
    {
      DDS4CCM_ERROR (1, (LM_ERROR, CLINFO
                    ACE_TEXT ("DDS_StateListen_T::remove - ")
                    ACE_TEXT ("Unable to cast StateListenerControl.\n")));
    }
  DDSSubscriberBase_type::remove (subscriber);
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED, DDS4CCM_Vendor VENDOR_TYPE>
::CCM_DDS::CCM_StateListenerControl_ptr
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::get_data_control (void)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>::get_data_control");

  return ::CCM_DDS::CCM_StateListenerControl::_duplicate (
    this->data_control_.in ());
}


