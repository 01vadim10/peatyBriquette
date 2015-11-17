<?xml version="1.0" encoding="UTF-8"?>
<?ARNC0 Version="1.28.1"?>
<LANGS defaultLangId="1">
  <!-- Command queue configuration (global setting - applies to all langauge interpreters) -->
  <CMDQUEUE BufferSize="15" />
  <!-- Memory configuration:
    <MEM
      LimitMB="<max memory usage>"  (if not specified, or set to "0", then all available system mem can be used)
      LimitPercent="<max memory usage>%" (percentage of free system memory (at startup) to limit the interpreter to)
      ReserveMB="<reserve memory size>"  (if not specified then a small default amount of memory is reserved)
  -->
  <MEM ReserveMB="5" LimitPercent="80%" />

  <!-- Execution configuration:
    <EXEC
      InstrBurstBG="<number of opcodes>"      How many opcodes to execute in one burst
      CycleBurstBG="<max cycle burst length>" Limited number of consecutive execution cycles allowed for interpreter (0=off)
      Stack="<size in bytes>"                 Main execution stack size
      MinorStack="<size in bytes>"            Default size for minor execution thread stacks, or explicitly:
      CStack="<cyclic thread stack size>"
      PStack="<path-synch thread stack size>"
      EStack="<eval thread stack size>"
  -->
  <EXEC InstrBurstBG="50" CycleBurstBG="0" Stack="16384" MinorStack="2048" EStack="1024" />

  <!-- Loader configuration: (how many lines to read and parse at once)
    <LOAD
      ReadLineBurstMax="<num_lines>"   (Number of lines to read from the input buffer at once when loader has full CPU - e.g. during PRELOAD) 
      ReadLineBurstMin="<num_lines>"   (Number of lines to read from the input buffer at once when loader is sharing CPU with execution) 
      ParseLineBurstMax="<num_lines>"  (Number of lines to parse at once when loader has full CPU - e.g. during PRELOAD) 
      ParseLineBurstMin="<num_lines>"  (Number of lines to parse at once when loader is sharing CPU with execution) 
  -->
  <LOAD ReadLineBurstMax="100" ReadLineBurstMin="20"
        ParseLineBurstMax="10" ParseLineBurstMin="2" />

  <!-- quiet startup: disable info messages (applied after loading this config file - all messages enabled until then) -->
  <DISABLE_MSG>
    15238 <!-- INFO: "Interpreter lib initialised" -->
    15336 <!-- INFO: "Loading interpreter config module" -->
    15337 <!-- INFO: "Loading interpreter config file" -->
    15666 <!-- INFO: "Precompiling language templates" -->
    <!-- 15240 INFO: "Program loaded" (from LANG_INCLUDE) -->
    <!-- 15778 WARN: "Logging file device does not exist" -->
    15784 <!-- INFO: "Log file scan complete ...file counts..." -->
  </DISABLE_MSG>
  <!-- very quiet startup: disable final interpreter-init-ok message -->
  <DISABLE_MSG>
    15740 <!-- INFO: "Interpreter initialized" -->
  </DISABLE_MSG>
  
  <!-- Configure languages... -->
  <LANG langId="1" langName="B&amp;R GCode" langModule="ailgcode">
    <LANGCONFIG Name="gmciplbr" />
    <LANGCONFIG Name="gmcipcbr" />
    <LANGCONFIG Name="gmcipubr" />
    <FILEEXT Name=".cnc" />
    <FILEEXT Name=".prg" />
    <MAINSEARCHPATH Name="$" FileDevice="CNC_PrgDir" />
    <MAINSEARCHPATH Name="$" DataObject="Yes" />
    <INCLUDEPATH Name="$" FileDevice="CNC_PrgDir" />
    <INCLUDEPATH Name="$" DataObject="Yes" />
  </LANG>
  <LANG langId="2" langName="Alternative Language 1 GCode" langModule="ailgcode">
    <LANGCONFIG Name="gmciplsm" />
    <LANGCONFIG Name="gmcipcbr" />
    <LANGCONFIG Name="gmcipcsm" />
    <LANGCONFIG Name="gmcipusm" />
    <!-- file extensions that identify this type of file -->
    <FILEPREFIX>_N_</FILEPREFIX> <!-- used only to help get the program name from the filename -->
    <FILEEXT>.MPF</FILEEXT>
    <FILEEXT>_MPF</FILEEXT>
    <FILEEXT>.SPF</FILEEXT>
    <FILEEXT>_SPF</FILEEXT>
    <!-- searchPath is used to find include files, and start-program file -->
    <MAINSEARCHPATH FileDevice="CNC_PrgDir">\$</MAINSEARCHPATH>
    <MAINSEARCHPATH FileDevice="CNC_PrgDir">\_N_MPF_DIR\$</MAINSEARCHPATH>
    <MAINSEARCHPATH FileDevice="CNC_PrgDir">\_N_SPF_DIR\$</MAINSEARCHPATH>
    <MAINSEARCHPATH DataObject="1">$</MAINSEARCHPATH>
    <!-- standard include path -->
    <INCLUDEPATH FileDevice="CNC_PrgDir">\$</INCLUDEPATH>
    <INCLUDEPATH FileDevice="CNC_PrgDir">\_N_SPF_DIR\$</INCLUDEPATH>
    <INCLUDEPATH FileDevice="CNC_PrgDir">\_N_MPF_DIR\$</INCLUDEPATH>
    <INCLUDEPATH DataObject="1">$</INCLUDEPATH>
  </LANG>
  <LANG langId="3" langName="IEC-ST" langModule="ailgcode">
    <LANGCONFIG Name="gmcipiec" />
    <!-- initial IEC configuration only supports reading type definition files -->
    <FILEEXT Name=".typ" />
    <MAINSEARCHPATH Name="$" FileDevice="TypDir" DataObject="No" />
    <INCLUDEPATH Name="$" FileDevice="TypDir" DataObject="No" />
  </LANG>
  <!-- MPLogging playback language config entry
     Note: here it is configured to only read NC channel 'A' log output file device,
           if necessary add MAINSEARCHPATH and INCLUDEPATH entries for other channels
     Also note: desination file device for saving log files is in gmcipcfg: <MPLOG FileDevice=".."/>
     
  <LANG langId="5" langName="MPLog" langModule="ailgcode">
    <LANGCONFIG Name="gmciplog" />
    <FILEEXT Name=".mpl" />
    <MAINSEARCHPATH Name="\$" FileDevice="mplogA" DataObject="No" />
    <INCLUDEPATH Name="\$" FileDevice="mplogA" DataObject="No" />
  </LANG>
  -->
</LANGS>