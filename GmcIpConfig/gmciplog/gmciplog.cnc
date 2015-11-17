<?xml version="1.0" encoding="utf-8"?>
<?ARNC0 Version="1.28.1"?>
<Root LangModule="ailgcode" Version="1.0">
  <AxesSpec>
    <!-- specify empty axes section to avoid warning -->
  </AxesSpec>
  <PVMacros>
    <!-- MP Data fields mapped as PVMacros -->
    <DR8><REF>#next_motion.Data.R8_value</REF></DR8>
    <DI4><REF>#next_motion.Data.I4_value</REF></DI4>
    <DU4><REF>#next_motion.Data.UI4_value</REF></DU4>
    <DR8_G211>
      <SET>
       %_CNC.TA = ${EXPR};
       if (%_CNC.TA &lt; 0)
         %_CNC.TA = 0;
       endif
        #next_motion.Data.R8_value = ${EXPR};
      </SET>
    </DR8_G211>
    
    <!-- LINEAR POSITION DATA -->
    <Dlp><REF>#next_motion.Data.LinMovement.Position</REF></Dlp>
    <Dli>
      <SET>
        <!-- data members need to be initialized to -1 -->
        #next_motion.Data.LinMovement.Idx[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.LinMovement.Idx = ${EXPR};
      </SET>
    </Dli>
    <Dlm>
      <SET>
        <!-- data members need to be initialized to -1 -->
        #next_motion.Data.LinMovement.Mode[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.LinMovement.Mode = ${EXPR};
      </SET>
    </Dlm>
    <!-- TRANS/ROT OFFSET DATA, note: (A)ROT_RPL just uses R8_value -->
    <Dto><REF>#next_motion.Data.Trans.Offset</REF></Dto>
    <Dti>
      <SET>
        <!-- data members need to be initialized to -1 -->
        #next_motion.Data.Trans.AxIdx[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.Trans.AxIdx = ${EXPR};
      </SET>
    </Dti>
    <Dtm>
      <SET>
        <!-- data members need to be initialized to -1 -->
        #next_motion.Data.Trans.Mode[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.Trans.Mode = ${EXPR};
      </SET>
    </Dtm>
    <!-- CIRCULAR MOVEMENT DATA -->
    <Dcp><REF>#next_motion.Data.CircMovement.Parameter</REF></Dcp>
    <Dci>
      <SET>
        <!-- data members need to be initialized to -1 -->
        #next_motion.Data.CircMovement.Idx[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.CircMovement.Idx = ${EXPR};
      </SET>
    </Dci>
    <Dcm>
      <SET>
        <!-- data members need to be initialized to -1 or do they? -->
        #next_motion.Data.CircMovement.Mode[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.CircMovement.Mode = ${EXPR};
      </SET>
    </Dcm>
    
    <Dtp><REF>#next_motion.Data.ToolAxOrient.Parameter</REF></Dtp>
    <Dts><REF>#next_motion.Data.ToolAxOrient.Sign</REF></Dts>
    <Daz><REF>#next_motion.Data.AbsZeroPtShift.ZpRecIdx</REF></Daz>
    <!-- PROGRAMMED ZERO POINT OFFSET DATA -->
    <Dpt>
      <SET>
        <!-- data members need to be initialized to -1 -->
        #next_motion.Data.ProgZeroPtShift.Type[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.ProgZeroPtShift.Type = ${EXPR};
      </SET>
    </Dpt>
    <Dpm>
      <SET>
        <!-- data members need to be initialized to -1 -->
        #next_motion.Data.ProgZeroPtShift.Mode[0] = ArrayRep(:(:-1:):);
        #next_motion.Data.ProgZeroPtShift.Mode = ${EXPR};
      </SET>
    </Dpm>
    <Dpa>   <REF>#next_motion.Data.ProgZeroPtShift.AxShift</REF></Dpa>
    
    <!-- FULL TOOL TRANSFORMATION DATA -->
    <Dfdx>  <REF>#next_motion.Data.FullTrfTool.Dx</REF></Dfdx>
    <Dfdy>  <REF>#next_motion.Data.FullTrfTool.Dy</REF></Dfdy>
    <Dfdz>  <REF>#next_motion.Data.FullTrfTool.Dz</REF></Dfdz>
    <Dfph>  <REF>#next_motion.Data.FullTrfTool.Phi</REF></Dfph>
    <Dft>   <REF>#next_motion.Data.FullTrfTool.Theta</REF></Dft>
    <Dfps>  <REF>#next_motion.Data.FullTrfTool.Psi</REF></Dfps>
    
    <!-- latch configuration data -->
    <DPLDli><REF>#next_motion.Data.PosLatchDistance.LatchIdx</REF></DPLDli>
    <DPLDts><REF>#next_motion.Data.PosLatchDistance.TriggSource</REF></DPLDts>
    <DPLDe> <REF>#next_motion.Data.PosLatchDistance.Edge</REF></DPLDe>
    <DPLDti><REF>#next_motion.Data.PosLatchDistance.HwTrigIdx</REF></DPLDti>
    <DPLDd> <REF>#next_motion.Data.PosLatchDistance.Distance</REF></DPLDd>
    
    <DPLli> <REF>#next_motion.Data.PosLatch.LatchIdx</REF></DPLli>
    <DPLts> <REF>#next_motion.Data.PosLatch.TriggSource</REF></DPLts>
    <DPLe>  <REF>#next_motion.Data.PosLatch.Edge</REF></DPLe>
    <DPLti> <REF>#next_motion.Data.PosLatch.HwTrigIdx</REF></DPLti>
    
    <!-- RADIUS FEED ADJUSTMENT DATA  -->
    <Drma>  <REF>#next_motion.Data.R_DependFeed.MaxRadius</REF></Drma>
    <Drmi>  <REF>#next_motion.Data.R_DependFeed.MinRadius</REF></Drmi>
    <Drr>   <REF>#next_motion.Data.R_DependFeed.Rate</REF></Drr>
    
    <!-- V JUMP DATA -->
    <Dsvp>
      <SET>
        <!-- data membeRs need to be initialized to ncOff -->
        #next_motion.Data.Set_v_jump.programmed[0] = ArrayRep(:(:ncOFF:):);
        #next_motion.Data.Set_v_jump.programmed = ${EXPR};
      </SET>
    </Dsvp>
    <Dsvv>  <REF>#next_motion.Data.Set_v_jump.value</REF></Dsvv>
    
    <!-- A JUMP DATA -->
    <Dsap>
      <SET>
        <!-- data membeRs need to be initialized to ncOff -->
        #next_motion.Data.Set_a_jump.programmed[0] = ArrayRep(:(:ncOFF:):);
        #next_motion.Data.Set_a_jump.programmed = ${EXPR};
      </SET>
    </Dsap>
    <Dsav>  <REF>#next_motion.Data.Set_a_jump.value</REF></Dsav>

    <!-- AXIS LIMIT DATA -->
    <Dsep>
      <SET>
        <!-- data membeRs need to be initialized to ncOff -->
        #next_motion.Data.SetAxLimit.programmed[0] = ArrayRep(:(:ncOFF:):);
        #next_motion.Data.SetAxLimit.programmed = ${EXPR};
      </SET>
    </Dsep>
    <Dser>  <REF>#next_motion.Data.SetAxLimit.RecordIdx</REF></Dser>
    
    <!-- CAMWRAPPING DATA -->
    <Dcad>  <REF>#next_motion.Data.CamWrapping.Diameter</REF></Dcad>
    <Dcap>  <REF>#next_motion.Data.CamWrapping.ParameterP1</REF></Dcap>

    <Dsu><REF>#next_motion.Data.SetPathAccDec.UnitType</REF></Dsu>
    
    <!-- ACC DEC DATA -->
    <Dsv108>
      <SET>
        #next_motion.Data.SetPathAccDec.value = ${EXPR};
        if (#next_motion.Data.SetPathAccDec.UnitType == 1)
          %_CNC.lim_path_acc_p = ${EXPR} / 100.0 * %_CNC.lim_path_acc_p_ini;
        else
          %_CNC.lim_path_acc_p = ${EXPR};
        endif
      </SET>
    </Dsv108>
    
    <Dsv109>
      <SET>
        #next_motion.Data.SetPathAccDec.value = ${EXPR};
        if (#next_motion.Data.SetPathAccDec.UnitType == 1)
          %_CNC.lim_path_acc_n = ${EXPR} / 100.0 * %_CNC.lim_path_acc_n_ini;
        else
          %_CNC.lim_path_acc_n = ${EXPR};
        endif
      </SET>
    </Dsv109>

    <Dsv110>
      <SET>
        #next_motion.Data.SetPathAccDec.value = ${EXPR};
        if (#next_motion.Data.SetPathAccDec.UnitType == 1)
          %_CNC.lim_path_acc_p = ${EXPR} / 100.0 * %_CNC.lim_path_acc_p_ini;
          %_CNC.lim_path_acc_n = ${EXPR} / 100.0 * %_CNC.lim_path_acc_n_ini;
        else
          %_CNC.lim_path_acc_p = ${EXPR};
          %_CNC.lim_path_acc_n = ${EXPR};
        endif
      </SET>
    </Dsv110>
    
    <Dsma>  <REF>#next_motion.Data.SetTransSpeed.MaxAngle</REF></Dsma>
    <Dsmi>  <REF>#next_motion.Data.SetTransSpeed.MinAngle</REF></Dsmi>
    <Dsr>   <REF>#next_motion.Data.SetTransSpeed.RedFactor</REF></Dsr>

    <!-- BEZIER SPLINE DATA -->
    <Dbrp>  <REF>#next_motion.Data.BezierSpline.RadiusProgrammed</REF></Dbrp>
    <Dbr>   <REF>#next_motion.Data.BezierSpline.Radius</REF></Dbr>
    <Dbvp>  <REF>#next_motion.Data.BezierSpline.VeProgrammed</REF></Dbvp>
    <Dbv>   <REF>#next_motion.Data.BezierSpline.Ve</REF></Dbv>
    <Dbl>   <REF>#next_motion.Data.BezierSpline.LinProgrammed</REF></Dbl>
    
    <Dao>   <REF>#next_motion.Data.AutomTangentialAx.Offset</REF></Dao>
    <Daa>   <REF>#next_motion.Data.AutomTangentialAx.AxIdx</REF></Daa>
    
    <!-- AXIS MAPPING DATA -->
    <DAMa>  <REF>#next_motion.Data.AxisMapping.AxIdx</REF></DAMa>
    <DAMf>  <REF>#next_motion.Data.AxisMapping.factor</REF></DAMf>
    <DAMp>  <REF>#next_motion.Data.AxisMapping.ParameterP1</REF></DAMp>
    
    <!-- SIGNAL PATH END DATA -->
    <DSPEt>  <REF>#next_motion.Data.SignalPathEnd.Time</REF></DSPEt> 
    <DSPEst> <REF>#next_motion.Data.SignalPathEnd.SignalType</REF></DSPEst>
    <DSPEsi> <REF>#next_motion.Data.SignalPathEnd.SignalIdx</REF></DSPEsi>
    <DSPEsd> <REF>#next_motion.Data.SignalPathEnd.SourceData</REF></DSPEsd>
    <DSPEd>  <REF>#next_motion.Data.SignalPathEnd.DataLength </REF></DSPEd>
    <DSPEp>  
      <SET>
        #next_motion.Data.SignalPathEnd.pDestination = \#sys_vars.EXF[0];
      </SET>
    </DSPEp>
    
    <!-- SIGNAL PATH END DISTDATA -->
    <DSPEDst><REF>#next_motion.Data.SignalPathEndDist.SignalType</REF></DSPEDst>
    <DSPEDsi><REF>#next_motion.Data.SignalPathEndDist.SignalIdx</REF></DSPEDsi>
    <DSPEDsd><REF>#next_motion.Data.SignalPathEndDist.SourceData</REF></DSPEDsd>
    <DSPEDd> <REF>#next_motion.Data.SignalPathEndDist.DataLength </REF></DSPEDd>
    <DSPEDp>  
      <SET>
        #next_motion.Data.SignalPathEndDist.pDestination = \#sys_vars.EXF[0];
      </SET>
    </DSPEDp>
        
    <!-- SIGNAL PREDICT DATA -->
    <DSPo>   <REF>#next_motion.Data.SignalPredict.Override</REF></DSPo>

    <!-- WS_CTRL DATA -->
    <DWCx1>  <REF>#next_motion.Data.WS_Ctrl.x1</REF></DWCx1>
    <DWCz1>  <REF>#next_motion.Data.WS_Ctrl.z1</REF></DWCz1>
    <DWCy1>  <REF>#next_motion.Data.WS_Ctrl.y1</REF></DWCy1>
    <DWCx2>  <REF>#next_motion.Data.WS_Ctrl.x2</REF></DWCx2>
    <DWCz2>  <REF>#next_motion.Data.WS_Ctrl.y2</REF></DWCz2>
    <DWCy2>  <REF>#next_motion.Data.WS_Ctrl.z2</REF></DWCy2>
    <DWCi>   <REF>#next_motion.Data.WS_Ctrl.index</REF></DWCi>
    <DWCc>   <REF>#next_motion.Data.WS_Ctrl.coord</REF></DWCc>
    <DWCp>   <REF>#next_motion.Data.WS_Ctrl.pplane</REF></DWCp>
    <DWCo>   <REF>#next_motion.Data.WS_Ctrl.orient</REF></DWCo>

    <DWCa>
      <SET>
        #next_motion.Data.WS_Ctrl.arm_diameter[0] = ArrayRep(:(:ncOFF:):);
        #next_motion.Data.WS_Ctrl.arm_diameter = ${EXPR};
      </SET>      
    </DWCa>
    
    <!-- TOOL DATA RECORD DATA -->    
    <DTDRt>  <REF>#next_motion.Data.ToolDataRecord.ToolIdx</REF></DTDRt>
    
    <!-- SYS VARS -->
    <Sz>     <REF>#sys_vars.ZP</REF></Sz>
    
    <!-- SPINDLE SPEED DATA -->
    <DSSi>   <REF>#next_motion.Data.SpindleSpeed.Idx</REF></DSSi>
    <DSSs>   <REF>#next_motion.Data.SpindleSpeed.speed</REF></DSSs>

    <!-- C2_SPLINE_START DATA -->
    <DCSSt>  <REF>#next_motion.Data.C2_SplineStart.BCType</REF></DCSSt>
    <DCSSv>  <REF>#next_motion.Data.C2_SplineStart.BCValue</REF></DCSSv>
    <DCSSp>
      <SET>
        #next_motion.Data.C2_SplineStart.BCProgrammed[0] = ArrayRep(:(:ncOFF:):);
        #next_motion.Data.C2_SplineStart.BCProgrammed = ${EXPR};
      </SET>      
    </DCSSp>
    <DCSSsp>  <REF>#next_motion.Data.C2_SplineStart.SegmentParameter</REF></DCSSsp>
    <DCSSst>  <REF>#next_motion.Data.C2_SplineStart.SegmentType</REF></DCSSst>

    <!-- C2_SPLINE_END DATA -->    
    <DCSEt>  <REF>#next_motion.Data.C2_SplineEnd.BCType</REF></DCSEt>
    <DCSEv>  <REF>#next_motion.Data.C2_SplineEnd.BCValue</REF></DCSEv>
    <DCSEp>
      <SET>
        #next_motion.Data.C2_SplineEnd.BCProgrammed[0] = ArrayRep(:(:ncOFF:):);
        #next_motion.Data.C2_SplineEnd.BCProgrammed = ${EXPR};
      </SET>
    </DCSEp>
    <DFd>    <REF>#next_motion.Data.Frame.Data</REF></DFd>
    
    <!-- SYSTEM VARIABLE DATA -->    
    <DSVs>   <REF>#next_motion.Data.SystemVariable.SysVarIdx</REF></DSVs>
    <DSVa>   <REF>#next_motion.Data.SystemVariable.AxIdx</REF></DSVa>
    <DSVd>   <REF>#next_motion.Data.SystemVariable.Data.R8_value</REF></DSVd>

  </PVMacros>
  <Constants>
    <PathBusy     type="STRING">BUSY</PathBusy>
    <PathStatus   type="STRING">STATUS</PathStatus>
    <PathErrLevel type="STRING">ERRLEV</PathErrLevel>
  </Constants>
  <BuiltInProcs>
    <!-- SendCommand only used prior to ARNC0 V1.25.0 -->
    <SendCommand MinArgs="1" MaxArgs="1" Inline="Yes">
      SendCommand(:$[1]:);
    </SendCommand>
    <DispatchAndWait MinArgs="1" MaxArgs="1" Inline="Yes">
      DispatchAndWait(:$[1]:);
    </DispatchAndWait>
  </BuiltInProcs>
  <Preprocess>
    <MP_PJN Search="MP22000 " Replace="PJN " />
    <MP_PJB Search="MP22100 " Replace="PJB " />
  </Preprocess>
  <GCodes>
    <!-- For MPLogging GCodes only used for commands that take args -->
    <G_DELAY GNum="0" Alias="@" AliasIsPattern="Yes" Inline="Yes">
       <Arg DataType="FLOAT" ref="tickdelay"/>
       #cycle_counter = 0;
      WaitUntil(:#cycle_counter &gt;= ${tickdelay}:);
    </G_DELAY>

    <!-- Path synchronous exec job : Non-Blocking -->
    <G_PJN GNum="22000" Alias="PJN" Inline="Yes"> <!-- need inline because we're using path-synch -->
      <Arg Name="PathBusy" DataType="FLOAT" ref="busy_count"/>
      <Arg Name="PathStatus" DataType="FLOAT" ref="final_status"/>
      <Arg Name="PathErrLevel" DataType="FLOAT" ref="error_level"/>
      #job->group_id = 0;
      #job->enable = 1;
      #job->is_fub = 1;
      #job->error_level = ${error_level};
      if (${busy_count} == 0)
        beginpathsynch
          @#job->terminate = 1;
          @#job->eval_status = ${final_status};
        endpathsynch
      else
        beginpathsynch
          begincyclic
          if (${busy_count} == @#job->eval_count)
            @#job->terminate = 1;
            @#job->eval_status = ${final_status};
          else
            @#job->eval_status = 65535;
          endif
          endcyclic
        endpathsynch
      endif
    </G_PJN>

    <!-- Path synchronous exec job : Blocking -->
    <G_PJB GNum="22100" Alias="PJB" Inline="Yes"> <!-- need inline because we're using path-synch -->
      <Arg Name="PathBusy" DataType="FLOAT" ref="busy_count"/>
      <Arg Name="PathStatus" DataType="FLOAT" ref="final_status"/>
      <Arg Name="PathErrLevel" DataType="FLOAT" ref="error_level"/>
      #job->group_id = 0;
      #job->enable = 1;
      #job->is_fub = 1;
      #job->error_level = ${error_level};
      #job->mp_command = MPCMD_PATH_SYNC_EXEC_WAIT;
      #job->is_blocking = 1;
      if (${busy_count} == 0)
        beginpathsynch
          @#job->terminate = 1;
          @#job->eval_status = ${final_status};
        endpathsynch
      else
        beginpathsynch
          begincyclic
            if (${busy_count} == @#job->eval_count)
              @#job->terminate = 1;
              @#job->eval_status = ${final_status};
            else
              @#job->eval_status = 65535;
            endif
          endcyclic
          WaitForCyclicJob(:#last_job_id:);
        endpathsynch
      endif
    </G_PJB>
  </GCodes>
  <MCodes>
  	<!-- MPLogging M-Codes are used for processing MPxxxx consts and the ; pushpacket call -->
    <M_DEFAULT IsDefault="Yes" MinValue="0" MaxValue="999999">
      <!-- MP Command number: MP<num> -->
      <ARG ref="VALUE" DataType="FLOAT" RequireLiteral="Yes" />
      #next_motion.Command = ${VALUE};
    </M_DEFAULT>
    <M10003 Value="10003" Inline="Yes">
      <!-- Abort MP must trigger a runtime error from the MPLog run -->
      <ARG ref="VALUE" DataType="FLOAT" RequireLiteral="Yes" />
      Error(:id:10003,msg:"LogAbort":);
    </M10003>
    <M1000000 Value="1000000" Alias=";" AliasIsPattern="Yes" Inline="Yes">
      <!-- PushPacket call --> 
      <ARG ref="VALUE" DataType="FLOAT" RequireLiteral="Yes" />
      PushPacket(::);
    </M1000000>
  </MCodes>
  <ParserData NestedComments="No" DefaultCaseSensitive="Yes" CommentsSpanLines="No"
     ReadWholeFileBeforeParsing="No" ExpectMainProgStmts="Yes" UseFubTemplates="No" >
    <TKG_END_OF_LINE IsPattern="No">\n</TKG_END_OF_LINE>
    <TKG_OPEN_COMMENT>#</TKG_OPEN_COMMENT>
    <TKG_NC_BLOCK_PREFIX IsPattern="Yes">N:[\s\d]</TKG_NC_BLOCK_PREFIX>
    <TKG_QUOTED_STRING IsPattern="Yes">""|"[^"]+"</TKG_QUOTED_STRING>
    <TKG_OPEN_LISTBRACKET>(</TKG_OPEN_LISTBRACKET>
    <TKG_CLOSE_LISTBRACKET>)</TKG_CLOSE_LISTBRACKET>
    <TKG_COMMA>,</TKG_COMMA>
    <TKG_NUMBER IsPattern="Yes">\d+\.\d+|\d+\.|\.\d+</TKG_NUMBER>
    <TKG_INTEGER IsPattern="Yes">\d+</TKG_INTEGER>
    <TKG_NUMBER_EXP IsPattern="Yes">e:[\s\d\+\-\.]</TKG_NUMBER_EXP>
    <TKG_ASSIGN_EQ>=</TKG_ASSIGN_EQ>
    <TKG_ARITH_BINARY_MINUS>-</TKG_ARITH_BINARY_MINUS>
    <TKG_M_CODE_PREFIX IsPattern="Yes">MP:\d</TKG_M_CODE_PREFIX>
  </ParserData>
</Root>
