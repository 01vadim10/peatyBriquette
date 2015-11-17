<?xml version="1.0" encoding="utf-8"?>
<?ARNC0 Version="1.28.1"?>
<Root LangModule="ailgcode" Version="1.0">
  <AxesSpec>
  </AxesSpec>
  <!-- avoid primtypes matching when followed by # to avoid conflicts with IEC literals (e.g. TIME#...) -->
  <PrimTypes PatternSuffix=":[^\d\w$#]">
    <!-- Specify what B&R datatypes correspond to the user-language defined types -->
    <!-- If the user declares a variable in their program, and the corresponding PV is
         of a different type, then a warning is issued -->
    <!-- Support for specifying B&R specific types -->
    <BOOL BRType="BOOL" />
    <STRING BRType="STRING" />
    <TIME BRType="TIME" />
    <SINT BRType="SINT" />
    <INT BRType="INT" />
    <DINT BRType="DINT" />
    <USINT BRType="USINT" />
    <UINT BRType="UINT" />
    <UDINT BRType="UDINT" />
    <REAL BRType="REAL" />
    <LREAL BRType="LREAL" />
    <DATE_AND_TIME BRType="DATE_AND_TIME" />
    <DT BRType="DT" />
  </PrimTypes>
  <ParserData NestedComments="Yes" DefaultCaseSensitive="Yes" CommentsSpanLines="Yes"
     ReadWholeFileBeforeParsing="Yes" ExpectMainProgStmts="No" UseFubTemplates="No" >
    <!--Patterns are specified as Perl regular expressions-->
    <!--Token Names should not be changed-->
    <!--Tokens without a Pattern or without TOKEN entry are not in use in this dialect-->
    <!--Restricted means this token can only match on a FollowedBy request-->
    <TKG_END_OF_LINE IsPattern="No">\n</TKG_END_OF_LINE>
    <TKG_OPEN_COMMENT>(*</TKG_OPEN_COMMENT>
    <TKG_CLOSE_COMMENT>*)</TKG_CLOSE_COMMENT>
    <TKG_TRUE IsPattern="Yes">TRUE:\W</TKG_TRUE>
    <TKG_FALSE IsPattern="Yes">FALSE:\W</TKG_FALSE>
    <TKG_PRIM_TYPE IsPattern="Yes" />
    <TKG_OPEN_BRACKET>(</TKG_OPEN_BRACKET>
    <TKG_CLOSE_BRACKET>)</TKG_CLOSE_BRACKET>
    <TKG_OPEN_INDEXBRACKET>[</TKG_OPEN_INDEXBRACKET>
    <TKG_CLOSE_INDEXBRACKET>]</TKG_CLOSE_INDEXBRACKET>
    <TKG_COMMA>,</TKG_COMMA>
    <TKG_INTEGER IsPattern="Yes">\d[\d_]+|\d</TKG_INTEGER>
    <TKG_POSITIVE>+</TKG_POSITIVE>
    <TKG_NEGATIVE>-</TKG_NEGATIVE>
    <TKG_REFERENCE  FollowedBy="TKG_IEC_TO" IsPattern="Yes">REFERENCE:\W</TKG_REFERENCE>
    <TKG_IEC_TO IsPattern="Yes">TO:\W</TKG_IEC_TO>
    <TKG_SUBRANGE>..</TKG_SUBRANGE >
    <TKG_TIME_LITERAL CaseSensitive="no" IsPattern="yes" >time#\-[dDhHmMsS_\.\d]+|time#[dDhHmMsS_\.\d]+|t#\-[dDhHmMsS_\.\d]+|t#[dDhHmMsS_\.\d]+</TKG_TIME_LITERAL>
    <TKG_ASSIGN_EQ>:=</TKG_ASSIGN_EQ>    
    <TKG_IEC_OPEN_TYPE IsPattern="Yes">TYPE:\W</TKG_IEC_OPEN_TYPE> 
    <TKG_IEC_CLOSE_TYPE IsPattern="Yes">END_TYPE:\W</TKG_IEC_CLOSE_TYPE> 
    <TKG_IEC_DATATYPE_SPEC>:</TKG_IEC_DATATYPE_SPEC> 
    <TKG_IEC_ARRAY IsPattern="Yes">ARRAY:\W</TKG_IEC_ARRAY> 
    <TKG_IEC_OF IsPattern="Yes">OF:\W</TKG_IEC_OF> 
    <TKG_IEC_DELIM>;</TKG_IEC_DELIM> 
    <TKG_IEC_OPEN_STRUCT IsPattern="Yes">STRUCT:\W</TKG_IEC_OPEN_STRUCT> 
    <TKG_IEC_CLOSE_STRUCT IsPattern="Yes">END_STRUCT:\W</TKG_IEC_CLOSE_STRUCT> 
    <TKG_WORD IsPattern="Yes">\w|\w[\w\d$]+</TKG_WORD> 
    <!-- This is a temporary token to allow the entire right hand side of
     a struct member initialization statement to be stored. --> 
    <TKG_STRUCT_INIT IsPattern="Yes" Restricted="Yes">[^;]+</TKG_STRUCT_INIT>
  </ParserData>
</Root>
