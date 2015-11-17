<?xml version="1.0" encoding="UTF-8"?>
<?ARNC0 Version="1.28.1"?>
<CONFIG>
  <!-- Example default language configuration (number and name from gmcipsys: <LANG .../>)

  <DEFAULT_LANG LangId="<number>" ...or... LangName="<name>" />

  Note: Either specify LangId or LangName
        If not specified, gmcipsys: <LANGS defaultLangId=".." >... is used
  -->

  <XML_INCLUDE Name="gmcipvar" IfNotExist="Warn" />
  <XML_INCLUDE Name="gmcipfun" IfNotExist="Warn" />
  <XML_INCLUDE Name="gmcipfub" IfNotExist="Warn" />
  
  <!-- Example .typ file loading instructions:
  
  <LANG_INCLUDE LangName="IEC-ST" Name="MyTypes" FileExt=".typ"
    FileDevice="CNC_PrgDir" DataObject="No"
    Scope="plc_global" IfNotExist="Warn" OnError="Error" />

  <LANG_INCLUDE LangName="IEC-ST" Name="Acp10man.typ" DataObject="No" />
  <LANG_INCLUDE LangName="IEC-ST" Name="arnc0man.typ" DataObject="No" />
  <LANG_INCLUDE LangName="IEC-ST" Name="acp10sdc.typ" DataObject="No" />
  
  Note: We strongly recommend not storing type files as data objects
        as this may cause confusion with the binary object of the same library name
  -->

  <MPQUEUE NumPackets="200" LookaheadMinBlocks="5" LookaheadMaxBlocks="20" LookaheadMode="any" MaxPathJobs="256" />
  <!-- Example Debug feature configuration (can be ommitted to adopt defaults)
  <DBG_IPVAR_ACCESS TableSize="24" />
  <DBG_BREAKPOINTS TableSize="48" />
  <DBG_EVAL_QUERY TableSize="12" MaxRetry="25" />
  -->

  <!-- Motion Packet Logging configuration.  Note: FileDevice="mplog*" means Ch1:"mplogA", Ch2:"mplogB", ... -->
  <MPLOG MaxBuffers="10" MinBuffers="4" EarlyCircleBufferLookahead="2" DefaultBufferSize="131072" TaskCycleDelay="1"
         FileDevice="mplog*" MaxLogFiles="20" MaxLogFileSize="1048576" CopyLineTextMaxChars="80" /> 

  <AXES StandardCNCAxes="Yes">
    <!--
    <CNCAXIS CNCIndex="3" Alias1="X1">A</CNCAXIS>
    <CNCAXIS CNCIndex="4" Alias1="Y1">B</CNCAXIS>
    <CNCAXIS CNCIndex="5" Alias1="Z1">C</CNCAXIS>
    <AUXAXIS PVRef="ax_obj[0]" Alias1="CENTER">ax1_obj</AUXAXIS>
    <AUXAXIS PVRef="ax_obj[1]" Alias1="LINEAR">ax2_obj</AUXAXIS>
    <AUXAXIS PVRef="ax_obj[2]" Alias1="ROTATION">ax3_obj</AUXAXIS>
    <AUXAXIS PVRef="ax_obj[3]" Alias1="UP_DOWN">ax4_obj</AUXAXIS>
    <AUXAXIS PVRef="ax_obj[4]" Alias1="LEFT_RIGHT">ax5_obj</AUXAXIS>
    <AUXAXIS PVRef="ax_obj[5]" Alias1="BEND_1">ax6_obj</AUXAXIS>
    <AUXAXIS PVRef="ax_obj[6]" Alias1="BEND_2">ax7_obj</AUXAXIS>
    -->
  </AXES>
  
  <FUBOutputs>
    <!-- Standard FUB Output rules -->
    <FUBOutput Name="PLCOpen">
      <ERROR condition="$Error == 1"/>
      <BUSY condition="$Busy == 1"/>    
    </FUBOutput>
    <FUBOutput Name="BuR">
      <ERROR condition="$status != 65535 &amp;&amp; $status != 0"/>
      <BUSY condition="$status == 65535"/>    
    </FUBOutput>
  </FUBOutputs>

</CONFIG>
