<?xml version="1.0" encoding="utf-8"?>
<?ARNC0 Version="1.28.1"?>
<Root LangModule="ailgcode" Version="1.0">
  <Constants>
    <NumAxes Type="INT">15</NumAxes>
  </Constants>
  <Preprocess>
    <!-- Support for AltLang1 system-global (NCK), and interpreter-global (CHAN) variable scope specifiers -->
    <PP_RULE_STOPRE Search="STOPRE" Replace="G172" />
  </Preprocess>
  <Types>
    <RotationAngleSpecifier type="ENUM" EnumType="REGEXP" Value6="H"  />
    <RadiusSpecifier type="ENUM" EnumType="REGEXP" Value1="R\s*="  />
    <InterpolParam type="ENUM" EnumType="REGEXP"
      Value0="I" Value1="J" Value2="K"
      Value100="G161\s*I" Value101="G161\s*J" Value102="G161\s*K"
      Value200="G162\s*I" Value201="G162\s*J" Value202="G162\s*K"
      Value0300="I\s*=\s*AC" Value0301="J\s*=\s*AC" Value0302="K\s*=\s*AC"
      Value0400="I\s*=\s*IC" Value0401="J\s*=\s*IC" Value0402="K\s*=\s*IC"
      />
    <CirclePointParam type="ENUM" EnumType="REGEXP"
      Value0="I1\s*=" Value1="J1\s*=" Value2="K1\s*="
      Value100="G161\s*I1\s*=" Value101="G161\s*J1\s*=" Value102="G161\s*K1\s*="
      Value200="G162\s*I1\s*=" Value201="G162\s*J1\s*=" Value202="G162\s*K1\s*="
      Value0300="I1\s*=\s*AC" Value0301="J1\s*=\s*AC" Value0302="K1\s*=\s*AC"
      Value0400="I1\s*=\s*IC" Value0401="J1\s*=\s*IC" Value0402="K1\s*=\s*IC"
      />
    <RPYAngleName type="ENUM" EnumType="REGEXP"
      Value1="ROLL" Value0="PITCH" Value2="YAW"
      />
    <EulerAngleName type="ENUM" EnumType="REGEXP"
      Value3="PHI" Value4="THETA" Value5="PSI"
      />
    <RotaryVectorName type="ENUM" EnumType="REGEXP"
      Value0="P\s*=" Value1="Q\s*=" Value2="R\s*="
      />
    <DwellTime type="FLOAT" />
    <RParamIndex type="INT" MinValue="0" MaxValue="999" />
    <EXParamIndex type="INT" MinValue="0" MaxValue="99" />
    <MParamIndex type="INT" MinValue="0" MaxValue="99" />
    <Byte type="INT" MinValue="0" MaxValue="255" />
    <Word type="INT" MinValue="-32768" MaxValue="32767" />
    <Long type="INT" />
  </Types>
  <PVMacros> <!-- Syntax that looks like PV refs, but is actually mapped to a defined bit of AIL -->
    <SAVE ArrayDims="0" Group="500" > <!-- issue MP to save state of modal GCodes, restore state on return from subprog -->
      <!-- implementation requires motion packet support -->
      <CALL>
        Info(:id:52101, msg:"Save Modal GCode State NOT SUPPORTED YET":);
      </CALL>
    </SAVE>
  </PVMacros>
  <SysVars>
    <!-- Note 1: Path synchronous system variables - prefix AIL variable with "@" --> 
    <!-- Note 2: variable type is as declared in ARNC0 --> 
    <!-- Note 3: CanRead and CanWrite permissions default to "Yes" if not specified --> 
    <!-- Note 4: If using <SET> and <GET> instead of <REF>, then do not specify CanRead/Write --> 

    <!-- CNC sourced system variables -->
    <P_F Name="$P_F">
      <GET>
        return @%_CNC.v_ncprog;
      </GET>
    </P_F>
    <P_GG Name="$P_GG">
      <GET>
        return @%_CNC.typ_ncblock;
      </GET>
    </P_GG>

    <LIM_PATH_V Name="$LIM_PATH_V">
        <GET>
        return %_CNC.lim_path_v;
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_CNC.lim_path_v = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 2;
          #next_motion.Data.SystemVariable.AxIdx = -1;
          #next_motion.Data.SystemVariable.Data.R8_value = %_CNC.lim_path_v;
          #next_motion.Command = MPCMD_CNC_SYS_VAR;
          PushPacket(::);
        </SET>
    </LIM_PATH_V>
    
    <LIM_PATH_ACC_P Name="$LIM_PATH_ACC_P">
        <GET>
        return %_CNC.lim_path_acc_p;
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_CNC.lim_path_acc_p = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 3;
          #next_motion.Data.SystemVariable.AxIdx = -1;
          #next_motion.Data.SystemVariable.Data.R8_value = %_CNC.lim_path_acc_p;
          #next_motion.Command = MPCMD_CNC_SYS_VAR;
          PushPacket(::);
        </SET>
    </LIM_PATH_ACC_P>
    
    <LIM_PATH_ACC_N Name="$LIM_PATH_ACC_N">
        <GET>
        return %_CNC.lim_path_acc_n;
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_CNC.lim_path_acc_n = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 4;
          #next_motion.Data.SystemVariable.AxIdx = -1;
          #next_motion.Data.SystemVariable.Data.R8_value = %_CNC.lim_path_acc_n;
          #next_motion.Command = MPCMD_CNC_SYS_VAR;
          PushPacket(::);
        </SET>
    </LIM_PATH_ACC_N>
    
    <S_JUMP_T Name="$S_JUMP_T">
        <GET>
        return %_CNC.s_jump_t;
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_CNC.s_jump_t = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 5;
          #next_motion.Data.SystemVariable.AxIdx = -1;
          #next_motion.Data.SystemVariable.Data.R8_value = %_CNC.s_jump_t;
          #next_motion.Command = MPCMD_CNC_SYS_VAR;
          PushPacket(::);
        </SET>
    </S_JUMP_T> 

    <RADIUS_ERR Name="$RADIUS_ERR">
        <GET>
        return %_CNC.radius_err;
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_CNC.radius_err = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 6;
          #next_motion.Data.SystemVariable.AxIdx = -1;
          #next_motion.Data.SystemVariable.Data.R8_value = %_CNC.radius_err;
          #next_motion.Command = MPCMD_CNC_SYS_VAR;
          PushPacket(::);
        </SET>
    </RADIUS_ERR>   

    <V_JUMP_T Name="$V_JUMP_T">
        <GET>
        return %_CNC.v_jump_t;
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_CNC.v_jump_t = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 11;
          #next_motion.Data.SystemVariable.AxIdx = -1;
          #next_motion.Data.SystemVariable.Data.R8_value = %_CNC.v_jump_t;
          #next_motion.Command = MPCMD_CNC_SYS_VAR;
          PushPacket(::);
        </SET>
    </V_JUMP_T> 

    <LIM_AX_ACC Name="$LIM_AX_ACC" ArrayDims="1">
        <GET>
        return %_AX.a_max_ncdy[$[1]];
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_AX.a_max_ncdy[$[1]] = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 11;
          #next_motion.Data.SystemVariable.AxIdx = $[1];
          #next_motion.Data.SystemVariable.Data.R8_value = %_AX.a_max_ncdy[$[1]];
          #next_motion.Command = MPCMD_AX_SYS_VAR;
          PushPacket(::);
        </SET>
    </LIM_AX_ACC>   

    <LIM_AX_V Name="$LIM_AX_V" ArrayDims="1">
        <GET>
        return %_AX.v_max_ncdy[$[1]];
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_AX.v_max_ncdy[$[1]] = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 12;
          #next_motion.Data.SystemVariable.AxIdx = $[1];
          #next_motion.Data.SystemVariable.Data.R8_value = %_AX.v_max_ncdy[$[1]];
          #next_motion.Command = MPCMD_AX_SYS_VAR;
          PushPacket(::);
        </SET>
    </LIM_AX_V> 

    <AX_A_JUMP Name="$AX_A_JUMP" ArrayDims="1">
       <GET>
          return %_AX.a_jump_ncdy[$[1]];
       </GET>
       <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_AX.a_jump_ncdy[$[1]] = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 13;
          #next_motion.Data.SystemVariable.AxIdx = $[1];
          #next_motion.Data.SystemVariable.Data.R8_value = %_AX.a_jump_ncdy[$[1]];
          #next_motion.Command = MPCMD_AX_SYS_VAR;
          PushPacket(::);
      </SET>
    </AX_A_JUMP>
    <AX_V_JUMP Name="$AX_V_JUMP" ArrayDims="1">
        <GET>
        return %_AX.v_jump_ncdy[$[1]];
        </GET>
        <SET>
        <ARG ref="EXPR" DataType="FLOAT" />
          %_AX.v_jump_ncdy[$[1]] = ${EXPR};
          #next_motion.Data.SystemVariable.SysVarIdx = 14;
          #next_motion.Data.SystemVariable.AxIdx = $[1];
          #next_motion.Data.SystemVariable.Data.R8_value = %_AX.v_jump_ncdy[$[1]];
          #next_motion.Command = MPCMD_AX_SYS_VAR;
          PushPacket(::);
        </SET>
    </AX_V_JUMP>    
    
    <AX_T_INPOS Name="$AX_T_INPOS" ArrayDims="1">
      <GET>
        return %_AX.t_inpos[$[1]];
      </GET>
    </AX_T_INPOS>    

    <AX_T_JOLT Name="$AX_T_JOLT" ArrayDims="1">
      <GET>
        return %_AX.t_jolt_ax[$[1]];
      </GET>
    </AX_T_JOLT>        
    
    <PATH_T_JOLT Name="$PATH_T_JOLT">
      <GET>
        return %_CNC.path_t_jolt;
      </GET>
    </PATH_T_JOLT>

    <!-- to calculate the absoulute value for G108/G110+percent value -->
    <LIM_PATH_ACC_P_INI Name="$LIM_PATH_ACC_P_INI">
      <GET>
        return %_CNC.lim_path_acc_p_ini;
      </GET>
    </LIM_PATH_ACC_P_INI>
    
    <!-- to calculate the absoulute value for G109/G110+percent value -->
    <LIM_PATH_ACC_N_INI Name="$LIM_PATH_ACC_N_INI">
      <GET>
        return %_CNC.lim_path_acc_n_ini;
      </GET>
    </LIM_PATH_ACC_N_INI>

    <!-- AXIS sourced system variables, CNC axis index number is the argument $AA_IM[0] -->
    <AA_IM Name="$AA_IM" ArrayDims="1">
      <GET>
        return @%_AX.set_pos_mcs[$[1]];
      </GET>
    </AA_IM>
    <AA_IW Name="$AA_IW" ArrayDims="1">
      <GET>
        return @%_AX.set_pos[$[1]];
      </GET>
    </AA_IW>
    <P_SIM Name="$P_SIM" ArrayDims="1">
      <GET>
        return %_AX.sim_status[$[1]];
      </GET>
    </P_SIM>    
    <MA_MAX_AX_ACCEL Name="$MA_MAX_AX_ACCEL" ArrayDims="1">
      <GET>
        return %_AX.a_max[$[1]];
      </GET>
    </MA_MAX_AX_ACCEL>    
    <MA_MAX_AX_VELO Name="$MA_MAX_AX_VELO" ArrayDims="1">
      <GET>
        return %_AX.v_max[$[1]];
      </GET>
    </MA_MAX_AX_VELO>    
    <MA_MAX_AX_JERK Name="$MA_MAX_AX_JERK" ArrayDims="1">
      <GET>
        return %_AX.jerk_max[$[1]];
      </GET>
    </MA_MAX_AX_JERK>    
    <MA_POSCTRL_GAIN Name="$MA_POSCTRL_GAIN" ArrayDims="1">
      <GET>
        return %_AX.servo_gain[$[1]];
      </GET>
    </MA_POSCTRL_GAIN>    
     <MA_REFP_SET_POS Name="$MA_REFP_SET_POS" ArrayDims="1">
      <GET>
        return %_AX.home_pos[$[1]];
      </GET>
    </MA_REFP_SET_POS>    
     <MA_POS_LIMIT_PLUS Name="$MA_POS_LIMIT_PLUS" ArrayDims="1">
      <GET>
        return %_AX.pos_sw_end[$[1]];
      </GET>
    </MA_POS_LIMIT_PLUS>    
     <MA_POS_LIMIT_MINUS Name="$MA_POS_LIMIT_MINUS" ArrayDims="1">
      <GET>
        return %_AX.neg_sw_end[$[1]];
      </GET>
    </MA_POS_LIMIT_MINUS>
  </SysVars>
  <Parameters>
    <!--Parameters are assumed to be asynchronous unless specified as Synchronous-->
    <R IndexType="RParamIndex" ValueType="FLOAT">
      <ARG ref="EXPR" DataType="RParamIndex" />
      #sys_vars.R[${EXPR}]
    </R>
    <QUOTED QuotedName="$R" Synchronous="Yes" IndexType="RParamIndex" ValueType="FLOAT">
      <ARG ref="EXPR" DataType="RParamIndex" />
      @#sys_vars.R[${EXPR}]
    </QUOTED>
    <!-- P## is the subroutine call repetition specifier -->
    <QUOTED QuotedName="$P" Synchronous="Yes" IndexType="RParamIndex" ValueType="FLOAT">
      <ARG ref="EXPR" DataType="RParamIndex" />
      @#sys_vars.R[@#sys_vars.R[${EXPR}]]
    </QUOTED>
    <EXB IndexType="EXParamIndex" ValueType="Byte">
      <ARG ref="EXPR" DataType="EXParamIndex" />
      #sys_vars.EXB[${EXPR}]
    </EXB>
    <EXW IndexType="EXParamIndex" ValueType="Word">
      <ARG ref="EXPR" DataType="EXParamIndex" />
      #sys_vars.EXW[${EXPR}]
    </EXW>
    <EXL IndexType="EXParamIndex" ValueType="Long">
      <ARG ref="EXPR" DataType="EXParamIndex" />
      #sys_vars.EXL[${EXPR}]
    </EXL>
    <EXF IndexType="EXFParamIndex" ValueType="FLOAT">
      <ARG ref="EXPR" DataType="EXFParamIndex" />
      #sys_vars.EXF[${EXPR}]
    </EXF>
    <!-- TODO: synchronous M-parameter support -->
    <MW Synchronous="Yes" IndexType="MParamIndex" ValueType="Word">
      <ARG ref="EXPR" DataType="MParamIndex" />
      @#sys_vars.MW[${EXPR}]
    </MW>
    <ML Synchronous="Yes" IndexType="MParamIndex" ValueType="Long">
      <ARG ref="EXPR" DataType="MParamIndex" />
      @#sys_vars.ML[${EXPR}]
    </ML>
    <MF Synchronous="Yes" IndexType="MParamIndex" ValueType="FLOAT">
      <ARG ref="EXPR" DataType="MParamIndex" />
      @#sys_vars.MF[${EXPR}]
    </MF>
  </Parameters>
  <MCodes>
    <!-- Scope-End M-Codes must be translated inline otherwise the "return;" calls have no effect -->
    <M17 Value="17" Group="41" Alias="RET:[^\d\w\(]" Eval="Early" Inline="Yes" AliasIsPattern="Yes">
      <ARG ref="VALUE" DataType="FLOAT" RequireLiteral="Yes" />
      #next_motion.Command = MPCMD_SET_M_FCT;
      #next_motion.Data.I4_value = ${VALUE};
      PushPacket(::);
      return;
    </M17>
    <M17_1 Value="17.1" Group="41" Alias="CONDRET" Eval="Early" Inline="Yes">
      <ARG ref="VALUE" DataType="FLOAT" RequireLiteral="Yes" />
      return;
    </M17_1>
  </MCodes>
</Root>
   
