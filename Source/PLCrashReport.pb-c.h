/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: PLCrashReport.proto */

#ifndef PROTOBUF_C_PLCrashReport_2eproto__INCLUDED
#define PROTOBUF_C_PLCrashReport_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Plcrash__CrashReport Plcrash__CrashReport;
typedef struct _Plcrash__CrashReport__Processor Plcrash__CrashReport__Processor;
typedef struct _Plcrash__CrashReport__SystemInfo Plcrash__CrashReport__SystemInfo;
typedef struct _Plcrash__CrashReport__ApplicationInfo Plcrash__CrashReport__ApplicationInfo;
typedef struct _Plcrash__CrashReport__Symbol Plcrash__CrashReport__Symbol;
typedef struct _Plcrash__CrashReport__Thread Plcrash__CrashReport__Thread;
typedef struct _Plcrash__CrashReport__Thread__StackFrame Plcrash__CrashReport__Thread__StackFrame;
typedef struct _Plcrash__CrashReport__Thread__RegisterValue Plcrash__CrashReport__Thread__RegisterValue;
typedef struct _Plcrash__CrashReport__BinaryImage Plcrash__CrashReport__BinaryImage;
typedef struct _Plcrash__CrashReport__Exception Plcrash__CrashReport__Exception;
typedef struct _Plcrash__CrashReport__Signal Plcrash__CrashReport__Signal;
typedef struct _Plcrash__CrashReport__Signal__MachException Plcrash__CrashReport__Signal__MachException;
typedef struct _Plcrash__CrashReport__ProcessInfo Plcrash__CrashReport__ProcessInfo;
typedef struct _Plcrash__CrashReport__MachineInfo Plcrash__CrashReport__MachineInfo;
typedef struct _Plcrash__CrashReport__ReportInfo Plcrash__CrashReport__ReportInfo;


/* --- enums --- */

/*
 * 
 * CPU Type Encodings
 * The wire format maintains support for multiple CPU type encodings; it is expected that different operating
 * systems may target different processors, and the reported CPU type and subtype information may not be
 * easily or directly expressed when not using the vendor's own defined types.
 * Currently, only Apple Mach CPU type/subtype information is supported by the wire protocol. These types are
 * stable, intended to be encoded in Mach-O files, and are defined in mach/machine.h on Mac OS X.
 * Implementations must gracefully handle the addition of unknown type encodings.
 */
typedef enum _Plcrash__CrashReport__Processor__TypeEncoding {
  /*
   * Unknown processor type encoding. 
   */
  PLCRASH__CRASH_REPORT__PROCESSOR__TYPE_ENCODING__TYPE_ENCODING_UNKNOWN = 0,
  /*
   * Apple Mach-defined processor types. 
   */
  PLCRASH__CRASH_REPORT__PROCESSOR__TYPE_ENCODING__TYPE_ENCODING_MACH = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(PLCRASH__CRASH_REPORT__PROCESSOR__TYPE_ENCODING)
} Plcrash__CrashReport__Processor__TypeEncoding;
/*
 * Known operating system types 
 */
typedef enum _Plcrash__CrashReport__SystemInfo__OperatingSystem {
  /*
   * Mac OS X 
   */
  PLCRASH__CRASH_REPORT__SYSTEM_INFO__OPERATING_SYSTEM__MAC_OS_X = 0,
  /*
   * iPhone OS 
   */
  PLCRASH__CRASH_REPORT__SYSTEM_INFO__OPERATING_SYSTEM__IPHONE_OS = 1,
  /*
   * iPhone Simulator (Mac OS X w/ simulator runtime environment) 
   */
  PLCRASH__CRASH_REPORT__SYSTEM_INFO__OPERATING_SYSTEM__IPHONE_SIMULATOR = 2,
  /*
   * Apple tvOS 
   */
  PLCRASH__CRASH_REPORT__SYSTEM_INFO__OPERATING_SYSTEM__APPLE_TVOS = 4,
  /*
   * Unknown operating system. 
   */
  PLCRASH__CRASH_REPORT__SYSTEM_INFO__OPERATING_SYSTEM__OS_UNKNOWN = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(PLCRASH__CRASH_REPORT__SYSTEM_INFO__OPERATING_SYSTEM)
} Plcrash__CrashReport__SystemInfo__OperatingSystem;
/*
 * Legacy processor architecture type codes. These codes have been deprecated. 
 */
typedef enum _Plcrash__Architecture {
  /*
   * x86 
   */
  PLCRASH__ARCHITECTURE__X86_32 = 0,
  /*
   * x86-64 
   */
  PLCRASH__ARCHITECTURE__X86_64 = 1,
  /*
   * ARMv6 
   */
  PLCRASH__ARCHITECTURE__ARMV6 = 2,
  /*
   * PPC 
   */
  PLCRASH__ARCHITECTURE__PPC = 3,
  /*
   ** PPC64 
   */
  PLCRASH__ARCHITECTURE__PPC64 = 4,
  /*
   * ARMv7 
   */
  PLCRASH__ARCHITECTURE__ARMV7 = 5,
  /*
   * Unknown processor type. 
   */
  PLCRASH__ARCHITECTURE__ARCHITECTURE_UNKNOWN = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(PLCRASH__ARCHITECTURE)
} Plcrash__Architecture;

/* --- messages --- */

/*
 * Processor information
 */
struct  _Plcrash__CrashReport__Processor
{
  ProtobufCMessage base;
  /*
   ** The CPU type encoding that should be used to interpret cpu_type and cpu_subtype. This value is required. 
   */
  protobuf_c_boolean has_encoding;
  Plcrash__CrashReport__Processor__TypeEncoding encoding;
  /*
   ** The CPU type. 
   */
  uint64_t type;
  /*
   ** The CPU subtype. 
   */
  uint64_t subtype;
};
#define PLCRASH__CRASH_REPORT__PROCESSOR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__processor__descriptor) \
    , 0, PLCRASH__CRASH_REPORT__PROCESSOR__TYPE_ENCODING__TYPE_ENCODING_UNKNOWN, 0, 0 }


struct  _Plcrash__CrashReport__SystemInfo
{
  ProtobufCMessage base;
  /*
   * Operating system 
   */
  protobuf_c_boolean has_operating_system;
  Plcrash__CrashReport__SystemInfo__OperatingSystem operating_system;
  /*
   * OS version 
   */
  char *os_version;
  /*
   * Processor architecture (deprecated in favor of machine_info) 
   */
  Plcrash__Architecture architecture;
  /*
   * Date crash report was generated (as seconds since epoch). 0 if the time
   * is unknown or can not be determined. 
   */
  int64_t timestamp;
  /*
   * OS build number (eg, 10J869) 
   */
  char *os_build;
};
#define PLCRASH__CRASH_REPORT__SYSTEM_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__system_info__descriptor) \
    , 0, PLCRASH__CRASH_REPORT__SYSTEM_INFO__OPERATING_SYSTEM__OS_UNKNOWN, NULL, PLCRASH__ARCHITECTURE__ARCHITECTURE_UNKNOWN, 0, NULL }


/*
 * Application info 
 */
struct  _Plcrash__CrashReport__ApplicationInfo
{
  ProtobufCMessage base;
  /*
   * Unique application identifier 
   */
  char *identifier;
  /*
   * Application version string 
   */
  char *version;
  /*
   * Application marketing version string 
   */
  char *marketing_version;
};
#define PLCRASH__CRASH_REPORT__APPLICATION_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__application_info__descriptor) \
    , NULL, NULL, NULL }


/*
 * A symbol table entry. 
 */
struct  _Plcrash__CrashReport__Symbol
{
  ProtobufCMessage base;
  /*
   * The symbol name 
   */
  char *name;
  /*
   * The symbol start address 
   */
  uint64_t start_address;
  /*
   * The symbol end address, if explicitly defined. This will only be included if the end address is
   * explicitly defined (eg, by DWARF debugging information), will not be derived by best-guess
   * heuristics. 
   */
  protobuf_c_boolean has_end_address;
  uint64_t end_address;
};
#define PLCRASH__CRASH_REPORT__SYMBOL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__symbol__descriptor) \
    , NULL, 0, 0, 0 }


/*
 * Stack frame 
 */
struct  _Plcrash__CrashReport__Thread__StackFrame
{
  ProtobufCMessage base;
  /*
   * Instruction pointer 
   */
  uint64_t pc;
  /*
   * Optional symbol information for this frame's PC. If computed client-side, this value is a best guess, and may
   * be inaccurate.
   * 
   * Symbol information may not be available, in which case this field will be excluded from the report.
   * This method of encoding symbol records is unfortunately ineffecient, as it is possible that the same
   * symbol will be included multiple times in a single crash report. Unfortunately, insofar as the crash reporter
   * must remain async-safe, there is no reasonable way to perform symbol uniquing at the time the report
   * is written. A future version of this format may resolve this issue, and migrate to the use of an index
   * into a shared symbol table.
   */
  Plcrash__CrashReport__Symbol *symbol;
};
#define PLCRASH__CRASH_REPORT__THREAD__STACK_FRAME__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__thread__stack_frame__descriptor) \
    , 0, NULL }


/*
 * A single register value 
 */
struct  _Plcrash__CrashReport__Thread__RegisterValue
{
  ProtobufCMessage base;
  /*
   * Register name (r1, ebp, ...) 
   */
  char *name;
  /*
   * Register value (32-bit or 64-bit) 
   */
  uint64_t value;
};
#define PLCRASH__CRASH_REPORT__THREAD__REGISTER_VALUE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__thread__register_value__descriptor) \
    , NULL, 0 }


/*
 * Thread state 
 */
struct  _Plcrash__CrashReport__Thread
{
  ProtobufCMessage base;
  /*
   * Thread number (indexed at 0, must be unique within a crash report) 
   */
  uint32_t thread_number;
  /*
   * Backtrace stack frames 
   */
  size_t n_frames;
  Plcrash__CrashReport__Thread__StackFrame **frames;
  /*
   * True if this is the crashed thread 
   */
  protobuf_c_boolean crashed;
  /*
   * Thread registers (required if this is the crashed thread, optional otherwise). Note that if an error occurs
   * during crash report generation, the register values may be missing for the crashed thread. 
   */
  size_t n_registers;
  Plcrash__CrashReport__Thread__RegisterValue **registers;
};
#define PLCRASH__CRASH_REPORT__THREAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__thread__descriptor) \
    , 0, 0,NULL, 0, 0,NULL }


/*
 * Binary image 
 */
struct  _Plcrash__CrashReport__BinaryImage
{
  ProtobufCMessage base;
  /*
   * Image base address 
   */
  uint64_t base_address;
  /*
   * Segment size 
   */
  uint64_t size;
  /*
   * Name of the binary image (should be a full path name) 
   */
  char *name;
  /*
   * 128-bit object UUID (matches Mach-O DWARF dSYM files) 
   */
  protobuf_c_boolean has_uuid;
  ProtobufCBinaryData uuid;
  /*
   * The image's code type. Should be included in all v1.1+ crash reports. The code type may differ between
   * binaries in the case of architectures with forwards-compatible code types, such as ARM, where armv6 and
   * armv7 images may be mixed. 
   */
  Plcrash__CrashReport__Processor *code_type;
};
#define PLCRASH__CRASH_REPORT__BINARY_IMAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__binary_image__descriptor) \
    , 0, 0, NULL, 0, {0,NULL}, NULL }


/*
 * Exception 
 */
struct  _Plcrash__CrashReport__Exception
{
  ProtobufCMessage base;
  /*
   * The exception name that triggered this crash 
   */
  char *name;
  /*
   * The exception reason 
   */
  char *reason;
  /*
   * The exception's original call stack, if available. This may be preserved across rethrow of an exception,
   * and can be used to determine the original call stack. 
   */
  size_t n_frames;
  Plcrash__CrashReport__Thread__StackFrame **frames;
};
#define PLCRASH__CRASH_REPORT__EXCEPTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__exception__descriptor) \
    , NULL, NULL, 0,NULL }


/*
 * Mach exception info.
 */
struct  _Plcrash__CrashReport__Signal__MachException
{
  ProtobufCMessage base;
  /*
   * The exception type. These values will generally be common across most Apple platforms. 
   */
  uint64_t type;
  /*
   * The exception codes. Interpretation of these values depends on the exception type, and/or the
   * faulting platform. 
   */
  size_t n_codes;
  uint64_t *codes;
};
#define PLCRASH__CRASH_REPORT__SIGNAL__MACH_EXCEPTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__signal__mach_exception__descriptor) \
    , 0, 0,NULL }


/*
 * Signal Information 
 */
struct  _Plcrash__CrashReport__Signal
{
  ProtobufCMessage base;
  /*
   ** Signal name 
   */
  char *name;
  /*
   * Signal code 
   */
  char *code;
  /*
   * Faulting instruction or address 
   */
  uint64_t address;
  /*
   * The Mach Exception that triggered the crash. This field will only be included in the
   * case that encoding crash reporter's exception-based reporting was enabled, and a Mach
   * exception was caught.
   * If the mach_exception field is defined, the legacy signal info will also be provided; this is required to maintain
   * backwards compatibility with existing report handlers. Note, however, that the signal info may be derived from the
   * Mach exception info by the encoding crash reporter, and thus may not exactly match the kernel exception-to-signal
   * mappings implemented in xnu. As such, when Mach exception data is available, its use should be preferred.
   */
  Plcrash__CrashReport__Signal__MachException *mach_exception;
};
#define PLCRASH__CRASH_REPORT__SIGNAL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__signal__descriptor) \
    , NULL, NULL, 0, NULL }


/*
 * Process Data. This was not available in earlier releases of the crash reporter and is marked optional
 * for compatibility. 
 */
struct  _Plcrash__CrashReport__ProcessInfo
{
  ProtobufCMessage base;
  /*
   * Application process name 
   */
  char *process_name;
  /*
   * Application process ID 
   */
  uint32_t process_id;
  /*
   * Application process path 
   */
  char *process_path;
  /*
   * Application parent process name 
   */
  char *parent_process_name;
  /*
   * Application parent process ID 
   */
  uint32_t parent_process_id;
  /*
   ** If false, the process is being run via process-level CPU emulation (such as Rosetta). 
   */
  protobuf_c_boolean native;
  /*
   ** The start time of the process (as seconds since UNIX epoch). The field may be
   * ommitted if the start time can not be determined. 
   */
  protobuf_c_boolean has_start_time;
  uint64_t start_time;
};
#define PLCRASH__CRASH_REPORT__PROCESS_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__process_info__descriptor) \
    , NULL, 0, NULL, NULL, 0, 0, 0, 0 }


/*
 * Host architecture information.
 */
struct  _Plcrash__CrashReport__MachineInfo
{
  ProtobufCMessage base;
  /*
   * Hardware model (eg, MacBookPro6,1) 
   */
  char *model;
  /*
   * The host processor. 
   */
  Plcrash__CrashReport__Processor *processor;
  /*
   * The number of actual physical processor cores. Note that the number of active processors may be managed by the
   * operating system's power management system, and this value may not reflect the number of active
   * processors at the time of the crash. 
   */
  uint32_t processor_count;
  /*
   * The number of logical processors.  Note that the number of active processors may be managed by the
   * operating system's power management system, and this value may not reflect the number of active
   * processors at the time of the crash.
   */
  uint32_t logical_processor_count;
};
#define PLCRASH__CRASH_REPORT__MACHINE_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__machine_info__descriptor) \
    , NULL, NULL, 0, 0 }


/*
 * Report format information
 */
struct  _Plcrash__CrashReport__ReportInfo
{
  ProtobufCMessage base;
  /*
   ** If true, this report was generated on request, and no crash occured. 
   */
  protobuf_c_boolean user_requested;
  /*
   ** A client-generated 16 byte OSF standard UUID for this report. May be used to filter duplicate reports submitted
   * by a single client. 
   */
  protobuf_c_boolean has_uuid;
  ProtobufCBinaryData uuid;
};
#define PLCRASH__CRASH_REPORT__REPORT_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__report_info__descriptor) \
    , 0, 0, {0,NULL} }


/*
 * A crash report 
 */
struct  _Plcrash__CrashReport
{
  ProtobufCMessage base;
  /*
   * Host system data 
   */
  Plcrash__CrashReport__SystemInfo *system_info;
  Plcrash__CrashReport__ApplicationInfo *application_info;
  /*
   * All backtraces 
   */
  size_t n_threads;
  Plcrash__CrashReport__Thread **threads;
  /*
   * All loaded binary images 
   */
  size_t n_binary_images;
  Plcrash__CrashReport__BinaryImage **binary_images;
  /*
   * The exception that triggered the crash (if any) 
   */
  Plcrash__CrashReport__Exception *exception;
  /*
   * The signal that triggered the crash 
   */
  Plcrash__CrashReport__Signal *signal;
  /*
   * The process info. Required for all v1.1+ crash reports. 
   */
  Plcrash__CrashReport__ProcessInfo *process_info;
  /*
   * Host architecture information. Required for all v1.1+ crash reports. If unavailable, the information
   * should be derived from the deprecated SystemInfo.architecture field. 
   */
  Plcrash__CrashReport__MachineInfo *machine_info;
  /*
   * Report format information. Required for all v1.1+ crash reports. 
   */
  Plcrash__CrashReport__ReportInfo *report_info;
  /*
   * Custom data. Can be used by user to store contextual information for the crash. 
   */
  protobuf_c_boolean has_custom_data;
  ProtobufCBinaryData custom_data;
};
#define PLCRASH__CRASH_REPORT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&plcrash__crash_report__descriptor) \
    , NULL, NULL, 0,NULL, 0,NULL, NULL, NULL, NULL, NULL, NULL, 0, {0,NULL} }


/* Plcrash__CrashReport__Processor methods */
void   plcrash__crash_report__processor__init
                     (Plcrash__CrashReport__Processor         *message);
/* Plcrash__CrashReport__SystemInfo methods */
void   plcrash__crash_report__system_info__init
                     (Plcrash__CrashReport__SystemInfo         *message);
/* Plcrash__CrashReport__ApplicationInfo methods */
void   plcrash__crash_report__application_info__init
                     (Plcrash__CrashReport__ApplicationInfo         *message);
/* Plcrash__CrashReport__Symbol methods */
void   plcrash__crash_report__symbol__init
                     (Plcrash__CrashReport__Symbol         *message);
/* Plcrash__CrashReport__Thread__StackFrame methods */
void   plcrash__crash_report__thread__stack_frame__init
                     (Plcrash__CrashReport__Thread__StackFrame         *message);
/* Plcrash__CrashReport__Thread__RegisterValue methods */
void   plcrash__crash_report__thread__register_value__init
                     (Plcrash__CrashReport__Thread__RegisterValue         *message);
/* Plcrash__CrashReport__Thread methods */
void   plcrash__crash_report__thread__init
                     (Plcrash__CrashReport__Thread         *message);
/* Plcrash__CrashReport__BinaryImage methods */
void   plcrash__crash_report__binary_image__init
                     (Plcrash__CrashReport__BinaryImage         *message);
/* Plcrash__CrashReport__Exception methods */
void   plcrash__crash_report__exception__init
                     (Plcrash__CrashReport__Exception         *message);
/* Plcrash__CrashReport__Signal__MachException methods */
void   plcrash__crash_report__signal__mach_exception__init
                     (Plcrash__CrashReport__Signal__MachException         *message);
/* Plcrash__CrashReport__Signal methods */
void   plcrash__crash_report__signal__init
                     (Plcrash__CrashReport__Signal         *message);
/* Plcrash__CrashReport__ProcessInfo methods */
void   plcrash__crash_report__process_info__init
                     (Plcrash__CrashReport__ProcessInfo         *message);
/* Plcrash__CrashReport__MachineInfo methods */
void   plcrash__crash_report__machine_info__init
                     (Plcrash__CrashReport__MachineInfo         *message);
/* Plcrash__CrashReport__ReportInfo methods */
void   plcrash__crash_report__report_info__init
                     (Plcrash__CrashReport__ReportInfo         *message);
/* Plcrash__CrashReport methods */
void   plcrash__crash_report__init
                     (Plcrash__CrashReport         *message);
size_t plcrash__crash_report__get_packed_size
                     (const Plcrash__CrashReport   *message);
size_t plcrash__crash_report__pack
                     (const Plcrash__CrashReport   *message,
                      uint8_t             *out);
size_t plcrash__crash_report__pack_to_buffer
                     (const Plcrash__CrashReport   *message,
                      ProtobufCBuffer     *buffer);
Plcrash__CrashReport *
       plcrash__crash_report__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   plcrash__crash_report__free_unpacked
                     (Plcrash__CrashReport *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Plcrash__CrashReport__Processor_Closure)
                 (const Plcrash__CrashReport__Processor *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__SystemInfo_Closure)
                 (const Plcrash__CrashReport__SystemInfo *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__ApplicationInfo_Closure)
                 (const Plcrash__CrashReport__ApplicationInfo *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__Symbol_Closure)
                 (const Plcrash__CrashReport__Symbol *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__Thread__StackFrame_Closure)
                 (const Plcrash__CrashReport__Thread__StackFrame *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__Thread__RegisterValue_Closure)
                 (const Plcrash__CrashReport__Thread__RegisterValue *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__Thread_Closure)
                 (const Plcrash__CrashReport__Thread *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__BinaryImage_Closure)
                 (const Plcrash__CrashReport__BinaryImage *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__Exception_Closure)
                 (const Plcrash__CrashReport__Exception *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__Signal__MachException_Closure)
                 (const Plcrash__CrashReport__Signal__MachException *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__Signal_Closure)
                 (const Plcrash__CrashReport__Signal *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__ProcessInfo_Closure)
                 (const Plcrash__CrashReport__ProcessInfo *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__MachineInfo_Closure)
                 (const Plcrash__CrashReport__MachineInfo *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport__ReportInfo_Closure)
                 (const Plcrash__CrashReport__ReportInfo *message,
                  void *closure_data);
typedef void (*Plcrash__CrashReport_Closure)
                 (const Plcrash__CrashReport *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    plcrash__architecture__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__processor__descriptor;
extern const ProtobufCEnumDescriptor    plcrash__crash_report__processor__type_encoding__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__system_info__descriptor;
extern const ProtobufCEnumDescriptor    plcrash__crash_report__system_info__operating_system__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__application_info__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__symbol__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__thread__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__thread__stack_frame__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__thread__register_value__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__binary_image__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__exception__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__signal__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__signal__mach_exception__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__process_info__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__machine_info__descriptor;
extern const ProtobufCMessageDescriptor plcrash__crash_report__report_info__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_PLCrashReport_2eproto__INCLUDED */
