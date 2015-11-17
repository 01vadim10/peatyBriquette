<?xml version="1.0" encoding="UTF-8"?>
<CONFIG>
  <FUNCTIONS>
  
    <!--
    
      C function prototypes to allow functions to be called directly from GCode program (or AIL template code)
      Examples:

      Example 1: RTC_gettime(ptr) from standard library: "SYS_LIB":
        <FUNC Name="RTC_gettime" RetType="UINT" ExecuteInSimulation="No">
            <ARG Name="RTCtime_struct" Type="UDINT" />
        </FUNC>

      Example 2: ncaction(ncobj,subject,action) from standard library: "Ncglobal":
        <FUNC Name="ncaction" RetType="UINT" ExecuteInSimulation="Yes">
            <ARG Name="nc_object" Type="UDINT" />
            <ARG Name="subject" Type="UINT" />
            <ARG Name="action" Type="UINT" />
        </FUNC>

      Example 3: User defined library function:
        <FUNC Name="myFun">
            <ARG Name="mode" Type="USINT" />
            <ARG Name="value" Type="UDINT" ref="Yes" />
        </FUNC>

    -->
    
  </FUNCTIONS>
</CONFIG>
