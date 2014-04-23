/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:12:BaseArgumentType

                     Type --(INT)  The type of Vector
            Integer_Value --(INT)  An Integer    
              Float_Value --(FLOAT)  A Floating Point Number
             String_Value --(STRING)  A String Variable
*/
typedef struct basargtyp BaseArgumentType;
struct basargtyp {
     INT ID;
     CHAR *Name;
     INT  Type;
     INT  Integer_Value;
     FLOAT  Float_Value;
     STRING *String_Value;
     };
#define BaseArgumentTypeSize sizeof(BaseArgumentType)
#define AllocateBaseArgumentType (BaseArgumentType *) Malloc(BaseArgumentTypeSize)
#define AllocArrayBaseArgumentType(n) (BaseArgumentType *) Calloc(n,BaseArgumentTypeSize)
#define BaseArgumentTypePntrSize sizeof(BaseArgumentType **)
#define AllocPntrArrayBaseArgumentType(n) (BaseArgumentType **) Calloc(n,BaseArgumentTypePntrSize)
#define SingCopyBaseArgumentType(out,in) memcpy(out,in,BaseArgumentTypeSize)
extern BaseArgumentType *CreateBaseArgumentType(BaseArgumentType *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  Type,
                                         INT  Integer_Value,
                                         FLOAT  Float_Value,
                                         STRING *String_Value);

extern CHAR *GetNameBaseArgumentType(BaseArgumentType *str);
extern INT  GetIDBaseArgumentType(BaseArgumentType *str);
extern void PrintBaseArgumentType(BaseArgumentType *eleptr);
extern void FreeBaseArgumentType(BaseArgumentType *eleptr);
extern void *AllocBaseArgumentType();
extern void WriteBinBaseArgumentType(BaseArgumentType *eleptr, DbaseLinkedList *file);
extern INT ReadBinBaseArgumentType(BaseArgumentType *eleptr, DbaseLinkedList *file);
extern void xdr_BaseArgumentType(XDR *stream, char **eleptr);
extern void CopyFullBaseArgumentType(BaseArgumentType *newstruct, BaseArgumentType *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:12:BaseArgumentTypeArray

           NumberOfValues --(INT) The Number of Values
                      Set --(BaseArgumentType) The Set of Values
*/
typedef struct baseargtyparray BaseArgumentTypeArray;
struct baseargtyparray {
     INT ID;
     CHAR *Name;
     INT  NumberOfValues;
     BaseArgumentType *Set;
     };
#define BaseArgumentTypeArraySize sizeof(BaseArgumentTypeArray)
#define AllocateBaseArgumentTypeArray (BaseArgumentTypeArray *) Malloc(BaseArgumentTypeArraySize)
#define AllocArrayBaseArgumentTypeArray(n) (BaseArgumentTypeArray *) Calloc(n,BaseArgumentTypeArraySize)
#define BaseArgumentTypeArrayPntrSize sizeof(BaseArgumentTypeArray **)
#define AllocPntrArrayBaseArgumentTypeArray(n) (BaseArgumentTypeArray **) Calloc(n,BaseArgumentTypeArrayPntrSize)
#define SingCopyBaseArgumentTypeArray(out,in) memcpy(out,in,BaseArgumentTypeArraySize)
extern BaseArgumentTypeArray *CreateBaseArgumentTypeArray(BaseArgumentTypeArray *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfValues,
                                                   BaseArgumentType *Set);

extern CHAR *GetNameBaseArgumentTypeArray(BaseArgumentTypeArray *str);
extern INT  GetIDBaseArgumentTypeArray(BaseArgumentTypeArray *str);
extern void PrintBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr);
extern void FreeBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr);
extern void *AllocBaseArgumentTypeArray();
extern void WriteBinBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr, DbaseLinkedList *file);
extern INT ReadBinBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr, DbaseLinkedList *file);
extern void xdr_BaseArgumentTypeArray(XDR *stream, char **eleptr);
extern void CopyFullBaseArgumentTypeArray(BaseArgumentTypeArray *newstruct, BaseArgumentTypeArray *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:200:VariableName

*/
typedef struct varname VariableName;
struct varname {
     INT ID;
     CHAR *Name;
     };
#define VariableNameSize sizeof(VariableName)
#define AllocateVariableName (VariableName *) Malloc(VariableNameSize)
#define AllocArrayVariableName(n) (VariableName *) Calloc(n,VariableNameSize)
#define VariableNamePntrSize sizeof(VariableName **)
#define AllocPntrArrayVariableName(n) (VariableName **) Calloc(n,VariableNamePntrSize)
#define SingCopyVariableName(out,in) memcpy(out,in,VariableNameSize)
extern VariableName *CreateVariableName(VariableName *newstruct,
                                 INT id,
                                 CHAR *name);

extern CHAR *GetNameVariableName(VariableName *str);
extern INT  GetIDVariableName(VariableName *str);
extern void PrintVariableName(VariableName *eleptr);
extern void FreeVariableName(VariableName *eleptr);
extern void *AllocVariableName();
extern void WriteBinVariableName(VariableName *eleptr, DbaseLinkedList *file);
extern INT ReadBinVariableName(VariableName *eleptr, DbaseLinkedList *file);
extern void xdr_VariableName(XDR *stream, char **eleptr);
extern void CopyFullVariableName(VariableName *newstruct, VariableName *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:200:FunctionInfo

                FunctCall --(FUNCTION)   The Function Call
*/
typedef struct funcinfo FunctionInfo;
struct funcinfo {
     INT ID;
     CHAR *Name;
     INT  (*FunctCall)();
     };
#define FunctionInfoSize sizeof(FunctionInfo)
#define AllocateFunctionInfo (FunctionInfo *) Malloc(FunctionInfoSize)
#define AllocArrayFunctionInfo(n) (FunctionInfo *) Calloc(n,FunctionInfoSize)
#define FunctionInfoPntrSize sizeof(FunctionInfo **)
#define AllocPntrArrayFunctionInfo(n) (FunctionInfo **) Calloc(n,FunctionInfoPntrSize)
#define SingCopyFunctionInfo(out,in) memcpy(out,in,FunctionInfoSize)
extern FunctionInfo *CreateFunctionInfo(FunctionInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  (*FunctCall)());

extern CHAR *GetNameFunctionInfo(FunctionInfo *str);
extern INT  GetIDFunctionInfo(FunctionInfo *str);
extern void PrintFunctionInfo(FunctionInfo *eleptr);
extern void FreeFunctionInfo(FunctionInfo *eleptr);
extern void *AllocFunctionInfo();
extern void WriteBinFunctionInfo(FunctionInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinFunctionInfo(FunctionInfo *eleptr, DbaseLinkedList *file);
extern void xdr_FunctionInfo(XDR *stream, char **eleptr);
extern void CopyFullFunctionInfo(FunctionInfo *newstruct, FunctionInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:200:TitleInfo

*/
typedef struct titleinfo TitleInfo;
struct titleinfo {
     INT ID;
     CHAR *Name;
     };
#define TitleInfoSize sizeof(TitleInfo)
#define AllocateTitleInfo (TitleInfo *) Malloc(TitleInfoSize)
#define AllocArrayTitleInfo(n) (TitleInfo *) Calloc(n,TitleInfoSize)
#define TitleInfoPntrSize sizeof(TitleInfo **)
#define AllocPntrArrayTitleInfo(n) (TitleInfo **) Calloc(n,TitleInfoPntrSize)
#define SingCopyTitleInfo(out,in) memcpy(out,in,TitleInfoSize)
extern TitleInfo *CreateTitleInfo(TitleInfo *newstruct,
                           INT id,
                           CHAR *name);

extern CHAR *GetNameTitleInfo(TitleInfo *str);
extern INT  GetIDTitleInfo(TitleInfo *str);
extern void PrintTitleInfo(TitleInfo *eleptr);
extern void FreeTitleInfo(TitleInfo *eleptr);
extern void *AllocTitleInfo();
extern void WriteBinTitleInfo(TitleInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinTitleInfo(TitleInfo *eleptr, DbaseLinkedList *file);
extern void xdr_TitleInfo(XDR *stream, char **eleptr);
extern void CopyFullTitleInfo(TitleInfo *newstruct, TitleInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:200:VariableNameSet

            NumberOfNames --(INT)   The Number of Names
                    Names --(VariableName)   The set of names
*/
typedef struct varnameset VariableNameSet;
struct varnameset {
     INT ID;
     CHAR *Name;
     INT  NumberOfNames;
     VariableName *Names;
     };
#define VariableNameSetSize sizeof(VariableNameSet)
#define AllocateVariableNameSet (VariableNameSet *) Malloc(VariableNameSetSize)
#define AllocArrayVariableNameSet(n) (VariableNameSet *) Calloc(n,VariableNameSetSize)
#define VariableNameSetPntrSize sizeof(VariableNameSet **)
#define AllocPntrArrayVariableNameSet(n) (VariableNameSet **) Calloc(n,VariableNameSetPntrSize)
#define SingCopyVariableNameSet(out,in) memcpy(out,in,VariableNameSetSize)
extern VariableNameSet *CreateVariableNameSet(VariableNameSet *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfNames,
                                       VariableName *Names);

extern CHAR *GetNameVariableNameSet(VariableNameSet *str);
extern INT  GetIDVariableNameSet(VariableNameSet *str);
extern void PrintVariableNameSet(VariableNameSet *eleptr);
extern void FreeVariableNameSet(VariableNameSet *eleptr);
extern void *AllocVariableNameSet();
extern void WriteBinVariableNameSet(VariableNameSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinVariableNameSet(VariableNameSet *eleptr, DbaseLinkedList *file);
extern void xdr_VariableNameSet(XDR *stream, char **eleptr);
extern void CopyFullVariableNameSet(VariableNameSet *newstruct, VariableNameSet *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:200:TitleInfoSet

           NumberOfTitles --(INT)   The Number of Titles
                   Titles --(TitleInfo)   The set of titles
*/
typedef struct titnameset TitleInfoSet;
struct titnameset {
     INT ID;
     CHAR *Name;
     INT  NumberOfTitles;
     TitleInfo *Titles;
     };
#define TitleInfoSetSize sizeof(TitleInfoSet)
#define AllocateTitleInfoSet (TitleInfoSet *) Malloc(TitleInfoSetSize)
#define AllocArrayTitleInfoSet(n) (TitleInfoSet *) Calloc(n,TitleInfoSetSize)
#define TitleInfoSetPntrSize sizeof(TitleInfoSet **)
#define AllocPntrArrayTitleInfoSet(n) (TitleInfoSet **) Calloc(n,TitleInfoSetPntrSize)
#define SingCopyTitleInfoSet(out,in) memcpy(out,in,TitleInfoSetSize)
extern TitleInfoSet *CreateTitleInfoSet(TitleInfoSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfTitles,
                                 TitleInfo *Titles);

extern CHAR *GetNameTitleInfoSet(TitleInfoSet *str);
extern INT  GetIDTitleInfoSet(TitleInfoSet *str);
extern void PrintTitleInfoSet(TitleInfoSet *eleptr);
extern void FreeTitleInfoSet(TitleInfoSet *eleptr);
extern void *AllocTitleInfoSet();
extern void WriteBinTitleInfoSet(TitleInfoSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinTitleInfoSet(TitleInfoSet *eleptr, DbaseLinkedList *file);
extern void xdr_TitleInfoSet(XDR *stream, char **eleptr);
extern void CopyFullTitleInfoSet(TitleInfoSet *newstruct, TitleInfoSet *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:201:KeyWordInfo

              KeyFlagName --(VariableName)   The Key Flag Length
*/
typedef struct keywordinfo KeyWordInfo;
struct keywordinfo {
     INT ID;
     CHAR *Name;
     VariableName *KeyFlagName;
     };
#define KeyWordInfoSize sizeof(KeyWordInfo)
#define AllocateKeyWordInfo (KeyWordInfo *) Malloc(KeyWordInfoSize)
#define AllocArrayKeyWordInfo(n) (KeyWordInfo *) Calloc(n,KeyWordInfoSize)
#define KeyWordInfoPntrSize sizeof(KeyWordInfo **)
#define AllocPntrArrayKeyWordInfo(n) (KeyWordInfo **) Calloc(n,KeyWordInfoPntrSize)
#define SingCopyKeyWordInfo(out,in) memcpy(out,in,KeyWordInfoSize)
extern KeyWordInfo *CreateKeyWordInfo(KeyWordInfo *newstruct,
                               INT id,
                               CHAR *name,
                               VariableName *KeyFlagName);

extern CHAR *GetNameKeyWordInfo(KeyWordInfo *str);
extern INT  GetIDKeyWordInfo(KeyWordInfo *str);
extern void PrintKeyWordInfo(KeyWordInfo *eleptr);
extern void FreeKeyWordInfo(KeyWordInfo *eleptr);
extern void *AllocKeyWordInfo();
extern void WriteBinKeyWordInfo(KeyWordInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinKeyWordInfo(KeyWordInfo *eleptr, DbaseLinkedList *file);
extern void xdr_KeyWordInfo(XDR *stream, char **eleptr);
extern void CopyFullKeyWordInfo(KeyWordInfo *newstruct, KeyWordInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:202:KeyWordSetInfo

             NumberOfKeys --(INT)   The Number of Keys
                     Keys --(KeyWordInfo)   The set of keys
*/
typedef struct keysetinfo KeyWordSetInfo;
struct keysetinfo {
     INT ID;
     CHAR *Name;
     INT  NumberOfKeys;
     KeyWordInfo *Keys;
     };
#define KeyWordSetInfoSize sizeof(KeyWordSetInfo)
#define AllocateKeyWordSetInfo (KeyWordSetInfo *) Malloc(KeyWordSetInfoSize)
#define AllocArrayKeyWordSetInfo(n) (KeyWordSetInfo *) Calloc(n,KeyWordSetInfoSize)
#define KeyWordSetInfoPntrSize sizeof(KeyWordSetInfo **)
#define AllocPntrArrayKeyWordSetInfo(n) (KeyWordSetInfo **) Calloc(n,KeyWordSetInfoPntrSize)
#define SingCopyKeyWordSetInfo(out,in) memcpy(out,in,KeyWordSetInfoSize)
extern KeyWordSetInfo *CreateKeyWordSetInfo(KeyWordSetInfo *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfKeys,
                                     KeyWordInfo *Keys);

extern CHAR *GetNameKeyWordSetInfo(KeyWordSetInfo *str);
extern INT  GetIDKeyWordSetInfo(KeyWordSetInfo *str);
extern void PrintKeyWordSetInfo(KeyWordSetInfo *eleptr);
extern void FreeKeyWordSetInfo(KeyWordSetInfo *eleptr);
extern void *AllocKeyWordSetInfo();
extern void WriteBinKeyWordSetInfo(KeyWordSetInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinKeyWordSetInfo(KeyWordSetInfo *eleptr, DbaseLinkedList *file);
extern void xdr_KeyWordSetInfo(XDR *stream, char **eleptr);
extern void CopyFullKeyWordSetInfo(KeyWordSetInfo *newstruct, KeyWordSetInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:203:ArgumentInfo

                     Type --(INT)   The Argument Type
                 FlagName --(VariableName)   The Flag Name
                    Title --(TitleInfo)   The Title
                  Default --(BaseArgumentType)   The Default Value
               UpperBound --(BaseArgumentType)   The Upper Bound
               LowerBound --(BaseArgumentType)   The Lower Bound
                  SetFlag --(INT)   The Flag denoting whether a set of arguments 
*/
typedef struct argueinfo ArgumentInfo;
struct argueinfo {
     INT ID;
     CHAR *Name;
     INT  Type;
     VariableName *FlagName;
     TitleInfo *Title;
     BaseArgumentType *Default;
     BaseArgumentType *UpperBound;
     BaseArgumentType *LowerBound;
     INT  SetFlag;
     };
#define ArgumentInfoSize sizeof(ArgumentInfo)
#define AllocateArgumentInfo (ArgumentInfo *) Malloc(ArgumentInfoSize)
#define AllocArrayArgumentInfo(n) (ArgumentInfo *) Calloc(n,ArgumentInfoSize)
#define ArgumentInfoPntrSize sizeof(ArgumentInfo **)
#define AllocPntrArrayArgumentInfo(n) (ArgumentInfo **) Calloc(n,ArgumentInfoPntrSize)
#define SingCopyArgumentInfo(out,in) memcpy(out,in,ArgumentInfoSize)
extern ArgumentInfo *CreateArgumentInfo(ArgumentInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  Type,
                                 VariableName *FlagName,
                                 TitleInfo *Title,
                                 BaseArgumentType *Default,
                                 BaseArgumentType *UpperBound,
                                 BaseArgumentType *LowerBound,
                                 INT  SetFlag);

extern CHAR *GetNameArgumentInfo(ArgumentInfo *str);
extern INT  GetIDArgumentInfo(ArgumentInfo *str);
extern void PrintArgumentInfo(ArgumentInfo *eleptr);
extern void FreeArgumentInfo(ArgumentInfo *eleptr);
extern void *AllocArgumentInfo();
extern void WriteBinArgumentInfo(ArgumentInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinArgumentInfo(ArgumentInfo *eleptr, DbaseLinkedList *file);
extern void xdr_ArgumentInfo(XDR *stream, char **eleptr);
extern void CopyFullArgumentInfo(ArgumentInfo *newstruct, ArgumentInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:204:ArgumentSetInfo

        NumberOfArguments --(INT)   Number of Arguments
                      Set --(ArgumentInfo)   The set of argument info
                   Values --(BaseArgumentType)   The Value of the argument
*/
typedef struct arguesetinfo ArgumentSetInfo;
struct arguesetinfo {
     INT ID;
     CHAR *Name;
     INT  NumberOfArguments;
     ArgumentInfo *Set;
     BaseArgumentType *Values;
     };
#define ArgumentSetInfoSize sizeof(ArgumentSetInfo)
#define AllocateArgumentSetInfo (ArgumentSetInfo *) Malloc(ArgumentSetInfoSize)
#define AllocArrayArgumentSetInfo(n) (ArgumentSetInfo *) Calloc(n,ArgumentSetInfoSize)
#define ArgumentSetInfoPntrSize sizeof(ArgumentSetInfo **)
#define AllocPntrArrayArgumentSetInfo(n) (ArgumentSetInfo **) Calloc(n,ArgumentSetInfoPntrSize)
#define SingCopyArgumentSetInfo(out,in) memcpy(out,in,ArgumentSetInfoSize)
extern ArgumentSetInfo *CreateArgumentSetInfo(ArgumentSetInfo *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfArguments,
                                       ArgumentInfo *Set,
                                       BaseArgumentType *Values);

extern CHAR *GetNameArgumentSetInfo(ArgumentSetInfo *str);
extern INT  GetIDArgumentSetInfo(ArgumentSetInfo *str);
extern void PrintArgumentSetInfo(ArgumentSetInfo *eleptr);
extern void FreeArgumentSetInfo(ArgumentSetInfo *eleptr);
extern void *AllocArgumentSetInfo();
extern void WriteBinArgumentSetInfo(ArgumentSetInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinArgumentSetInfo(ArgumentSetInfo *eleptr, DbaseLinkedList *file);
extern void xdr_ArgumentSetInfo(XDR *stream, char **eleptr);
extern void CopyFullArgumentSetInfo(ArgumentSetInfo *newstruct, ArgumentSetInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:205:KeyArgumentInfo

               KeySetName --(VariableName)   The Key Set Name
             ArgumentName --(VariableName)   The Argument Name
                    Title --(TitleInfo)   The Title
*/
typedef struct keyargue KeyArgumentInfo;
struct keyargue {
     INT ID;
     CHAR *Name;
     VariableName *KeySetName;
     VariableName *ArgumentName;
     TitleInfo *Title;
     };
#define KeyArgumentInfoSize sizeof(KeyArgumentInfo)
#define AllocateKeyArgumentInfo (KeyArgumentInfo *) Malloc(KeyArgumentInfoSize)
#define AllocArrayKeyArgumentInfo(n) (KeyArgumentInfo *) Calloc(n,KeyArgumentInfoSize)
#define KeyArgumentInfoPntrSize sizeof(KeyArgumentInfo **)
#define AllocPntrArrayKeyArgumentInfo(n) (KeyArgumentInfo **) Calloc(n,KeyArgumentInfoPntrSize)
#define SingCopyKeyArgumentInfo(out,in) memcpy(out,in,KeyArgumentInfoSize)
extern KeyArgumentInfo *CreateKeyArgumentInfo(KeyArgumentInfo *newstruct,
                                       INT id,
                                       CHAR *name,
                                       VariableName *KeySetName,
                                       VariableName *ArgumentName,
                                       TitleInfo *Title);

extern CHAR *GetNameKeyArgumentInfo(KeyArgumentInfo *str);
extern INT  GetIDKeyArgumentInfo(KeyArgumentInfo *str);
extern void PrintKeyArgumentInfo(KeyArgumentInfo *eleptr);
extern void FreeKeyArgumentInfo(KeyArgumentInfo *eleptr);
extern void *AllocKeyArgumentInfo();
extern void WriteBinKeyArgumentInfo(KeyArgumentInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinKeyArgumentInfo(KeyArgumentInfo *eleptr, DbaseLinkedList *file);
extern void xdr_KeyArgumentInfo(XDR *stream, char **eleptr);
extern void CopyFullKeyArgumentInfo(KeyArgumentInfo *newstruct, KeyArgumentInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:206:KeyArgumentSet

             NumberOfKeys --(INT)   The Number Of keys
             KeyArguments --(KeyArgumentInfo)   The Set of Keys
*/
typedef struct keyargueset KeyArgumentSet;
struct keyargueset {
     INT ID;
     CHAR *Name;
     INT  NumberOfKeys;
     KeyArgumentInfo *KeyArguments;
     };
#define KeyArgumentSetSize sizeof(KeyArgumentSet)
#define AllocateKeyArgumentSet (KeyArgumentSet *) Malloc(KeyArgumentSetSize)
#define AllocArrayKeyArgumentSet(n) (KeyArgumentSet *) Calloc(n,KeyArgumentSetSize)
#define KeyArgumentSetPntrSize sizeof(KeyArgumentSet **)
#define AllocPntrArrayKeyArgumentSet(n) (KeyArgumentSet **) Calloc(n,KeyArgumentSetPntrSize)
#define SingCopyKeyArgumentSet(out,in) memcpy(out,in,KeyArgumentSetSize)
extern KeyArgumentSet *CreateKeyArgumentSet(KeyArgumentSet *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfKeys,
                                     KeyArgumentInfo *KeyArguments);

extern CHAR *GetNameKeyArgumentSet(KeyArgumentSet *str);
extern INT  GetIDKeyArgumentSet(KeyArgumentSet *str);
extern void PrintKeyArgumentSet(KeyArgumentSet *eleptr);
extern void FreeKeyArgumentSet(KeyArgumentSet *eleptr);
extern void *AllocKeyArgumentSet();
extern void WriteBinKeyArgumentSet(KeyArgumentSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinKeyArgumentSet(KeyArgumentSet *eleptr, DbaseLinkedList *file);
extern void xdr_KeyArgumentSet(XDR *stream, char **eleptr);
extern void CopyFullKeyArgumentSet(KeyArgumentSet *newstruct, KeyArgumentSet *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:207:SysLstArgumentInfo

                SysLstKey --(VariableName)   The System List Key Name
*/
typedef struct syslstargue SysLstArgumentInfo;
struct syslstargue {
     INT ID;
     CHAR *Name;
     VariableName *SysLstKey;
     };
#define SysLstArgumentInfoSize sizeof(SysLstArgumentInfo)
#define AllocateSysLstArgumentInfo (SysLstArgumentInfo *) Malloc(SysLstArgumentInfoSize)
#define AllocArraySysLstArgumentInfo(n) (SysLstArgumentInfo *) Calloc(n,SysLstArgumentInfoSize)
#define SysLstArgumentInfoPntrSize sizeof(SysLstArgumentInfo **)
#define AllocPntrArraySysLstArgumentInfo(n) (SysLstArgumentInfo **) Calloc(n,SysLstArgumentInfoPntrSize)
#define SingCopySysLstArgumentInfo(out,in) memcpy(out,in,SysLstArgumentInfoSize)
extern SysLstArgumentInfo *CreateSysLstArgumentInfo(SysLstArgumentInfo *newstruct,
                                             INT id,
                                             CHAR *name,
                                             VariableName *SysLstKey);

extern CHAR *GetNameSysLstArgumentInfo(SysLstArgumentInfo *str);
extern INT  GetIDSysLstArgumentInfo(SysLstArgumentInfo *str);
extern void PrintSysLstArgumentInfo(SysLstArgumentInfo *eleptr);
extern void FreeSysLstArgumentInfo(SysLstArgumentInfo *eleptr);
extern void *AllocSysLstArgumentInfo();
extern void WriteBinSysLstArgumentInfo(SysLstArgumentInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysLstArgumentInfo(SysLstArgumentInfo *eleptr, DbaseLinkedList *file);
extern void xdr_SysLstArgumentInfo(XDR *stream, char **eleptr);
extern void CopyFullSysLstArgumentInfo(SysLstArgumentInfo *newstruct, SysLstArgumentInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:208:SysLstArgumentSet

                NumSysLst --(INT)   The number of SysLst Arguments
          SysLstArguments --(SysLstArgumentInfo)   The Set of SysLst Arguments
*/
typedef struct syslstset SysLstArgumentSet;
struct syslstset {
     INT ID;
     CHAR *Name;
     INT  NumSysLst;
     SysLstArgumentInfo *SysLstArguments;
     };
#define SysLstArgumentSetSize sizeof(SysLstArgumentSet)
#define AllocateSysLstArgumentSet (SysLstArgumentSet *) Malloc(SysLstArgumentSetSize)
#define AllocArraySysLstArgumentSet(n) (SysLstArgumentSet *) Calloc(n,SysLstArgumentSetSize)
#define SysLstArgumentSetPntrSize sizeof(SysLstArgumentSet **)
#define AllocPntrArraySysLstArgumentSet(n) (SysLstArgumentSet **) Calloc(n,SysLstArgumentSetPntrSize)
#define SingCopySysLstArgumentSet(out,in) memcpy(out,in,SysLstArgumentSetSize)
extern SysLstArgumentSet *CreateSysLstArgumentSet(SysLstArgumentSet *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumSysLst,
                                           SysLstArgumentInfo *SysLstArguments);

extern CHAR *GetNameSysLstArgumentSet(SysLstArgumentSet *str);
extern INT  GetIDSysLstArgumentSet(SysLstArgumentSet *str);
extern void PrintSysLstArgumentSet(SysLstArgumentSet *eleptr);
extern void FreeSysLstArgumentSet(SysLstArgumentSet *eleptr);
extern void *AllocSysLstArgumentSet();
extern void WriteBinSysLstArgumentSet(SysLstArgumentSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysLstArgumentSet(SysLstArgumentSet *eleptr, DbaseLinkedList *file);
extern void xdr_SysLstArgumentSet(XDR *stream, char **eleptr);
extern void CopyFullSysLstArgumentSet(SysLstArgumentSet *newstruct, SysLstArgumentSet *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands   */
/* Structure:209:CommandInfo

                 FlagName --(VariableName)   The Flag name 
                 Function --(FunctionInfo)   The Function Parameters
                  Comment --(TitleInfo)   This is the info about the function (text)
                Arguments --(ArgumentSetInfo)   The Set of Arguments
                     Keys --(KeyArgumentSet)   The Set of keys
                SysLstSet --(SysLstArgumentSet)   Set of SysLst Arguments
               KeySetInfo --(KeyWordSetInfo)   KeyWord definitions
                   Output --(SysLstArgumentSet)   Set of Ouput Arguments
                   Checks --(SysLstArgumentSet)   Set of Extra Checks
           NumSubCommands --(INT)   The number of Sub commands
              SubCommands --(CommandInfo)   The set of SubCommands
*/
typedef struct commandinfo CommandInfo;
struct commandinfo {
     INT ID;
     CHAR *Name;
     VariableName *FlagName;
     FunctionInfo *Function;
     TitleInfo *Comment;
     ArgumentSetInfo *Arguments;
     KeyArgumentSet *Keys;
     SysLstArgumentSet *SysLstSet;
     KeyWordSetInfo *KeySetInfo;
     SysLstArgumentSet *Output;
     SysLstArgumentSet *Checks;
     INT  NumSubCommands;
     CommandInfo *SubCommands;
     };
#define CommandInfoSize sizeof(CommandInfo)
#define AllocateCommandInfo (CommandInfo *) Malloc(CommandInfoSize)
#define AllocArrayCommandInfo(n) (CommandInfo *) Calloc(n,CommandInfoSize)
#define CommandInfoPntrSize sizeof(CommandInfo **)
#define AllocPntrArrayCommandInfo(n) (CommandInfo **) Calloc(n,CommandInfoPntrSize)
#define SingCopyCommandInfo(out,in) memcpy(out,in,CommandInfoSize)
extern CommandInfo *CreateCommandInfo(CommandInfo *newstruct,
                               INT id,
                               CHAR *name,
                               VariableName *FlagName,
                               FunctionInfo *Function,
                               TitleInfo *Comment,
                               ArgumentSetInfo *Arguments,
                               KeyArgumentSet *Keys,
                               SysLstArgumentSet *SysLstSet,
                               KeyWordSetInfo *KeySetInfo,
                               SysLstArgumentSet *Output,
                               SysLstArgumentSet *Checks,
                               INT  NumSubCommands,
                               CommandInfo *SubCommands);

extern CHAR *GetNameCommandInfo(CommandInfo *str);
extern INT  GetIDCommandInfo(CommandInfo *str);
extern void PrintCommandInfo(CommandInfo *eleptr);
extern void FreeCommandInfo(CommandInfo *eleptr);
extern void *AllocCommandInfo();
extern void WriteBinCommandInfo(CommandInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinCommandInfo(CommandInfo *eleptr, DbaseLinkedList *file);
extern void xdr_CommandInfo(XDR *stream, char **eleptr);
extern void CopyFullCommandInfo(CommandInfo *newstruct, CommandInfo *oldstruct);
