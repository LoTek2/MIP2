
//#define MIP_NO_ENTRY

#define MIP_DEBUG_PRINT_SOCKET
// nc -U -l -k /tmp/mip.socket

//----------------------------------------------------------------------

#include "plugin/clap/mip_clap.h"
#include "plugin/mip_plugin.h"


//----------------------------------------------------------------------
//
//
//
//----------------------------------------------------------------------

const clap_plugin_descriptor_t template_descriptor = {
   .clap_version  = CLAP_VERSION,
   .id            = "me/template/0",
   .name          = "template",
   .vendor        = "me",
   .url           = "https://my_website.com",
   .manual_url    = "",
   .support_url   = "",
   .version       = "0.0.0",
   .description   = "",
   .features      =  (const char *[]){ CLAP_PLUGIN_FEATURE_AUDIO_EFFECT, nullptr }
};

//----------

//enum myParameterEnums {
//  MY_PARAM1 = 0,
//  MY_PARAM2,
//  MY_PARAM3,
//  MY_PARAM_COUNT
//};
//
//const clap_param_info_t myParameters[MY_PARAM_COUNT] = {
//  { MY_PARAM1, CLAP_PARAM_IS_AUTOMATABLE, nullptr, "param1", "", 0, 1, 0 },
//  { MY_PARAM2, CLAP_PARAM_IS_AUTOMATABLE, nullptr, "param2", "", -1, 1, 1 },
//  { MY_PARAM3, CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED, nullptr, "param3", "", -12, 12, 0 }
//};
//
//const clap_audio_port_info_t myAudioInputPorts[] = {
//  { 0, "audio in 1", CLAP_AUDIO_PORT_IS_MAIN, 2, CLAP_PORT_STEREO, CLAP_INVALID_ID }
//};
//
//const clap_audio_port_info_t myAudioOutputPorts[] = {
//  { 0, "audio out 1", CLAP_AUDIO_PORT_IS_MAIN, 2, CLAP_PORT_STEREO, CLAP_INVALID_ID }
//};
//
//const clap_note_port_info_t myNoteInputPorts[] = {
//  { 0, CLAP_NOTE_DIALECT_CLAP, CLAP_NOTE_DIALECT_CLAP, "note in 1" }
//};
//
//const clap_note_port_info_t myNoteOutputPorts[] = {
//  { 0, CLAP_NOTE_DIALECT_CLAP, CLAP_NOTE_DIALECT_CLAP, "note out 1" }
//};

//----------------------------------------------------------------------
//
//
//
//----------------------------------------------------------------------

class template_plugin
: public MIP_Plugin {

//------------------------------
private:
//------------------------------

  enum myParameterEnums {
    MY_PARAM1 = 0,
    MY_PARAM2,
    MY_PARAM3,
    MY_PARAM_COUNT
  };

  const clap_param_info_t myParameters[MY_PARAM_COUNT] = {
    { MY_PARAM1, CLAP_PARAM_IS_AUTOMATABLE, nullptr, "param1", "", 0, 1, 0 },
    { MY_PARAM2, CLAP_PARAM_IS_AUTOMATABLE, nullptr, "param2", "", -1, 1, 1 },
    { MY_PARAM3, CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED, nullptr, "param3", "", -12, 12, 0 }
  };

  const clap_audio_port_info_t myAudioInputPorts[1] = {
    { 0, "audio in 1", CLAP_AUDIO_PORT_IS_MAIN, 2, CLAP_PORT_STEREO, CLAP_INVALID_ID }
  };

  const clap_audio_port_info_t myAudioOutputPorts[1] = {
    { 0, "audio out 1", CLAP_AUDIO_PORT_IS_MAIN, 2, CLAP_PORT_STEREO, CLAP_INVALID_ID }
  };

  const clap_note_port_info_t myNoteInputPorts[1] = {
    { 0, CLAP_NOTE_DIALECT_CLAP, CLAP_NOTE_DIALECT_CLAP, "note in 1" }
  };

  const clap_note_port_info_t myNoteOutputPorts[1] = {
    { 0, CLAP_NOTE_DIALECT_CLAP, CLAP_NOTE_DIALECT_CLAP, "note out 1" }
  };

//------------------------------
public:
//------------------------------

  template_plugin(const clap_plugin_descriptor_t* ADescriptor, const clap_host_t* AHost)
  : MIP_Plugin(ADescriptor,AHost) {
  }

  //----------

  virtual ~template_plugin() {
  }

//------------------------------
public: // plugin
//------------------------------

  bool init() final {
    appendAudioInputPort( &myAudioInputPorts[0] );
    appendAudioOutputPort(&myAudioOutputPorts[0]);
    appendNoteInputPort(  &myNoteInputPorts[0]  );
    appendNoteOutputPort( &myNoteOutputPorts[0] );
    for (uint32_t i=0; i<MY_PARAM_COUNT; i++) {
      appendParameter( new MIP_Parameter(&myParameters[i]) );
    }
    return true;
  }

  //bool activate(double sample_rate, uint32_t min_frames_count, uint32_t max_frames_count) final {
  //  return true;
  //}

  //bool start_processing() final {
  //  return true;
  //}

  //----------

  //void preProcessEvents(const clap_input_events_t* in_events, const clap_output_events_t* out_events) final {}
  //void postProcessEvents(const clap_input_events_t* in_events, const clap_output_events_t* out_events) final {}
  //void processEvents(const clap_input_events_t* in_events, const clap_output_events_t* out_events) final {}
  //void processEvent(const clap_event_header_t* header) final {}
  //void processNoteOnEvent(const clap_event_note_t* event) final {}
  //void processNoteOffEvent(const clap_event_note_t* event) final {}
  //void processNoteChokeEvent(const clap_event_note_t* event) final {}
  //void processNoteEndEvent(const clap_event_note_t* event) final {}
  //void processNoteExpressionEvent(const clap_event_note_expression_t* event) final {}
  //void processParamValueEvent(const clap_event_param_value_t* event) final {}
  //void processParamModEvent(const clap_event_param_mod_t* event) final {}
  //void processParamGestureBeginEvent(const clap_event_param_gesture_t* event) final {}
  //void processParamGestureEndEvent(const clap_event_param_gesture_t* event) final {}
  //void processTransportEvent(const clap_event_transport_t* event) final {}
  //void processMidiEvent(const clap_event_midi_t* event) final {}
  //void processMidiSysexEvent(const clap_event_midi_sysex_t* event) final {}
  //void processMidi2Event(const clap_event_midi2_t* event) final {}

  //void processAudioBlock(const clap_process_t* process) final {}
  //void processTransport(const clap_event_transport_t* transport) final {}

};

//----------------------------------------------------------------------
//
//
//
//----------------------------------------------------------------------

#ifndef MIP_NO_ENTRY

  #include "plugin/clap/mip_clap_entry.h"
  #include "plugin/mip_registry.h"

  //----------

  void MIP_Register(MIP_Registry* ARegistry) {
    ARegistry->appendDescriptor(&template_descriptor);
  };

  //----------

  MIP_Plugin* MIP_CreatePlugin(uint32_t AIndex, const clap_plugin_descriptor_t* ADescriptor, const clap_host_t* AHost) {
    if (AIndex == 0) {
      return new template_plugin(ADescriptor,AHost);
    }
    return nullptr;
  }

#endif
