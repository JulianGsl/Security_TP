/*
   Yara Rule Set
   Author: yarGen Rule Generator
   Date: 2018-10-18
   Identifier: isola
   Reference: https://github.com/Neo23x0/yarGen
*/

/* Rule Set ----------------------------------------------------------------- */

import "pe"

rule Firefox {
   meta:
      description = "isola - file Firefox"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2018-10-18"
      hash1 = "70ec370a766da746cfe1da74d2ce413b5243b28811925ee440fe0dc0eefd79e2"
   strings:
      $s1 = "exec $debugger $moz_debugger_args --args $MOZ_LIBDIR/$MOZ_APP_NAME \"$@\"" fullword ascii
      $s2 = "#  Alexander Sack <asac@jwsdot.com>" fullword ascii
      $s3 = "-- ) # Stop option processing" fullword ascii
      $s4 = "MOZ_APP_LAUNCHER=`readlink -f $MOZ_APP_LAUNCHER`" fullword ascii
      $s5 = "#  Chris Coulson <chris.coulson@canonical.com>" fullword ascii
      $s6 = "# temporary profiles used during alpha and beta phases." fullword ascii
      $s7 = "exec $debugger $moz_debugger_args $MOZ_LIBDIR/$MOZ_APP_NAME \"$@\"" fullword ascii
      $s8 = "#  Steve Langasek <steve.langasek@canonical.com>" fullword ascii
      $s9 = "$MOZ_LIBDIR/$MOZ_APP_NAME -h | sed -e 's,/.*/,,'" fullword ascii
      $s10 = "echo \"$MOZ_APP_NAME has not been compiled with valgrind support\"" fullword ascii
      $s11 = "echo \"      -d or --debugger       Specify debugger to start with (eg, gdb or valgrind)\"" fullword ascii
      $s12 = "while [ ! -x $MOZ_LIBDIR/$MOZ_APP_NAME ] ; do" fullword ascii
      $s13 = "exec $MOZ_LIBDIR/$MOZ_APP_NAME \"$@\"" fullword ascii
      $s14 = "#  Fabien Tassin <fta@sofaraway.org>" fullword ascii
      $s15 = "if [ ! -x $debugger ] ; then" fullword ascii
      $s16 = "# Firefox launcher containing a Profile migration helper for" fullword ascii
      $s17 = "echo \"      -a or --debugger-args  Specify arguments for debugger\"" fullword ascii
      $s18 = "echo \"      -g or --debug          Start within debugger\"" fullword ascii
      $s19 = "*)" fullword ascii /* reversed goodware string ')*' */
      $s20 = "# Authors:" fullword ascii
   condition:
      ( uint16(0) == 0x2123 and
         filesize < 7KB and
         ( 8 of them )
      ) or ( all of them )
}


rule Safari {
   meta:
      description = "isola - file Safari"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2018-10-18"
      hash1 = "8bb7a95c7f9692efd7923f127d544b1389a4d67eb92830139a23d5ab75c2efee"
   strings:
      $s1 = "<key>com.apple.private.appleaccount.app-hidden-from-icloud-settings</key>" fullword ascii
      $s2 = "/System/Library/PrivateFrameworks/Safari.framework/Versions/A/Safari" fullword ascii
      $s3 = "<key>com.apple.private.cloudkit.systemService</key>" fullword ascii
      $s4 = "<key>com.apple.private.extension-host.safari-extension-companion</key>" fullword ascii
      $s5 = "<key>com.apple.private.extension-host.safari-content-blocker</key>" fullword ascii
      $s6 = "<key>com.apple.private.extension-host.safari-extension</key>" fullword ascii
      $s7 = ")http://www.apple.com/certificateauthority0" fullword ascii
      $s8 = "DYLD_VERSIONED_FRAMEWORK_PATH=/System/Library/StagedFrameworks/Safari" fullword ascii
      $s9 = "<key>com.apple.private.ubiquity-additional-kvstore-identifiers</key>" fullword ascii
      $s10 = "<key>com.apple.private.safari.can-use-launch-agent</key>" fullword ascii
      $s11 = "__mh_execute_header" fullword ascii
      $s12 = "%http://www.apple.com/appleca/root.crl0" fullword ascii
      $s13 = "<key>com.apple.developer.ubiquity-kvstore-identifier</key>" fullword ascii
      $s14 = "<key>com.apple.private.imcore.imagent</key>" fullword ascii
      $s15 = "<key>com.apple.private.subscriptionservice.internal</key>" fullword ascii
      $s16 = "<key>com.apple.rootless.storage.SafariFamily</key>" fullword ascii
      $s17 = "<key>com.apple.private.aps-connection-initiate</key>" fullword ascii
      $s18 = "<key>com.apple.accounts.appleaccount.fullaccess</key>" fullword ascii
      $s19 = "<key>com.apple.private.accounts.allaccounts</key>" fullword ascii
      $s20 = "<key>com.apple.private.security.storage.cookies</key>" fullword ascii
   condition:
      uint16(0) == 0xfacf and
      (( uint16(0) == 0xfacf and
         filesize < 60KB and
         ( 8 of them )
      ) or ( all of them ))
}


rule chrome {
   meta:
      description = "isola - file chrome.exe"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2018-10-18"
      hash1 = "aa53ffb6fda174b3999a2b637ed9bde70ae2d7c7e1d19af95fb605c420bf2efc"
   strings:
      $x1 = "<assembly xmlns=\"urn:schemas-microsoft-com:asm.v1\" manifestVersion=\"1.0\"><dependency><dependentAssembly><assemblyIdentity ty" ascii
      $s2 = "api-ms-win-core-synch-l1-2-0.dll" fullword wide /* reversed goodware string 'lld.0-2-1l-hcnys-eroc-niw-sm-ipa' */
      $s3 = "win32\" name=\"Microsoft.Windows.Common-Controls\" version=\"6.0.0.0\" processorArchitecture=\"*\" publicKeyToken=\"6595b64144cc" ascii
      $s4 = "../../third_party/crashpad/crashpad/snapshot/minidump/process_snapshot_minidump.cc" fullword ascii
      $s5 = "CHECK failed: (n) <= (std::numeric_limits<size_t>::max() - kHeaderSize): " fullword ascii
      $s6 = "C:\\b\\c\\b\\win64_clang\\src\\out\\Release_x64\\initialexe\\chrome.exe.pdb" fullword ascii
      $s7 = "::GetNamedPipeClientProcessId" fullword ascii
      $s8 = "OutOfProcessHeapProfilingDumpProvider" fullword ascii
      $s9 = "https://support.google.com/chrome/contact/chromeuninstall3?hl=$1" fullword wide
      $s10 = "PruneCrashReportDatabase: Failed to get completed reports" fullword ascii
      $s11 = "failed to read target address" fullword ascii
      $s12 = "GetProcessBasicInformation failed" fullword ascii
      $s13 = "USER_PROCESS_PARAMETERS<crashpad::process_types::internal::Traits64>]" fullword ascii
      $s14 = "USER_PROCESS_PARAMETERS<crashpad::process_types::internal::Traits32>]" fullword ascii
      $s15 = "bytes).  To increase the limit (or to disable these warnings), see CodedInputStream::SetTotalBytesLimit() in google/protobuf/io" fullword ascii
      $s16 = ":schemas-microsoft-com:asm.v3\"><security><requestedPrivileges><requestedExecutionLevel level=\"asInvoker\" uiAccess=\"false\"><" ascii
      $s17 = "../../base/trace_event/process_memory_dump.cc" fullword ascii
      $s18 = "ProcessPrivateUsage" fullword ascii
      $s19 = "RegisterWaitForSingleObject non-crash dump requested" fullword ascii
      $s20 = "RegisterWaitForSingleObject crash dump requested" fullword ascii
   condition:
      ( uint16(0) == 0x5a4d and
         filesize < 5000KB and
         pe.imphash() == "a1d83ff3bf4e5a50858ac0be0fcd2394" and pe.exports("GetHandleVerifier") and
         ( 1 of ($x*) or 4 of them )
      ) or ( all of them )
}

/* Super Rules ------------------------------------------------------------- */

