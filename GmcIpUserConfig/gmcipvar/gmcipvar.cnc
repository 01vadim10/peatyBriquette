<?xml version="1.0" encoding="UTF-8"?>
<CONFIG>
  <VARIABLES>
  
    <!--
    
      Declarations of PLC-Variables to be available in the G-code programs (without need to redeclare)
      Example 1: <PV Type="REAL">myPlcVar</PV>
      Example 2: <PV Alias="my2ndPlcVar" Synch="path_synch" Type="UDINT" AryDim1="10">task:structure.ten_udints</PV>
      
      Interpreter-internal variables to be available in every G-Code program (without need to redeclare)
      Example 3: (PLC-scope - shared between interpreters):
          <VAR Scope="nc_global" Type="DINT">ncg_int</VAR>
      Example 4: (Channel-scope, shared between programs within a channel): 
          <VAR Scope="ip_global" Synch="path_synch" Type="LREAL" AryDim1="5" AryDim2="3">my2dDoubleArray</VAR>
          
    -->
    
  </VARIABLES>
</CONFIG>
