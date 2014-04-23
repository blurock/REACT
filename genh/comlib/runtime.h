/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:10:AliasString

                  KeyWord --(STRING) The string to be substituted
                    Alias --(STRING) The value to be inserted for keyword
*/
typedef struct aliasstring AliasString;
struct aliasstring {
     INT ID;
     CHAR *Name;
     STRING *KeyWord;
     STRING *Alias;
     };
#define AliasStringSize sizeof(AliasString)
#define AllocateAliasString (AliasString *) Malloc(AliasStringSize)
#define AllocArrayAliasString(n) (AliasString *) Calloc(n,AliasStringSize)
#define AliasStringPntrSize sizeof(AliasString **)
#define AllocPntrArrayAliasString(n) (AliasString **) Calloc(n,AliasStringPntrSize)
#define SingCopyAliasString(out,in) memcpy(out,in,AliasStringSize)
extern AliasString *CreateAliasString(AliasString *newstruct,
                               INT id,
                               CHAR *name,
                               STRING *KeyWord,
                               STRING *Alias);

extern CHAR *GetNameAliasString(AliasString *str);
extern INT  GetIDAliasString(AliasString *str);
extern void PrintAliasString(AliasString *eleptr);
extern void FreeAliasString(AliasString *eleptr);
extern void *AllocAliasString();
extern void WriteBinAliasString(AliasString *eleptr, DbaseLinkedList *file);
extern INT ReadBinAliasString(AliasString *eleptr, DbaseLinkedList *file);
extern void xdr_AliasString(XDR *stream, char **eleptr);
extern void CopyFullAliasString(AliasString *newstruct, AliasString *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:11:AliasArray

                MaxNumber --(INT) The maximum (for add alias routine)
          NumberOfAliases --(INT) The number of aliases
                      Set --(AliasString) The Set of Aliases
*/
typedef struct aliasarray AliasArray;
struct aliasarray {
     INT ID;
     CHAR *Name;
     INT  MaxNumber;
     INT  NumberOfAliases;
     AliasString *Set;
     };
#define AliasArraySize sizeof(AliasArray)
#define AllocateAliasArray (AliasArray *) Malloc(AliasArraySize)
#define AllocArrayAliasArray(n) (AliasArray *) Calloc(n,AliasArraySize)
#define AliasArrayPntrSize sizeof(AliasArray **)
#define AllocPntrArrayAliasArray(n) (AliasArray **) Calloc(n,AliasArrayPntrSize)
#define SingCopyAliasArray(out,in) memcpy(out,in,AliasArraySize)
extern AliasArray *CreateAliasArray(AliasArray *newstruct,
                             INT id,
                             CHAR *name,
                             INT  MaxNumber,
                             INT  NumberOfAliases,
                             AliasString *Set);

extern CHAR *GetNameAliasArray(AliasArray *str);
extern INT  GetIDAliasArray(AliasArray *str);
extern void PrintAliasArray(AliasArray *eleptr);
extern void FreeAliasArray(AliasArray *eleptr);
extern void *AllocAliasArray();
extern void WriteBinAliasArray(AliasArray *eleptr, DbaseLinkedList *file);
extern INT ReadBinAliasArray(AliasArray *eleptr, DbaseLinkedList *file);
extern void xdr_AliasArray(XDR *stream, char **eleptr);
extern void CopyFullAliasArray(AliasArray *newstruct, AliasArray *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:300:CommandLevel

                     Next --(CommandLevel) The next Deeper Level
*/
typedef struct commandlevel CommandLevel;
struct commandlevel {
     INT ID;
     CHAR *Name;
     CommandLevel *Next;
     };
#define CommandLevelSize sizeof(CommandLevel)
#define AllocateCommandLevel (CommandLevel *) Malloc(CommandLevelSize)
#define AllocArrayCommandLevel(n) (CommandLevel *) Calloc(n,CommandLevelSize)
#define CommandLevelPntrSize sizeof(CommandLevel **)
#define AllocPntrArrayCommandLevel(n) (CommandLevel **) Calloc(n,CommandLevelPntrSize)
#define SingCopyCommandLevel(out,in) memcpy(out,in,CommandLevelSize)
extern CommandLevel *CreateCommandLevel(CommandLevel *newstruct,
                                 INT id,
                                 CHAR *name,
                                 CommandLevel *Next);

extern CHAR *GetNameCommandLevel(CommandLevel *str);
extern INT  GetIDCommandLevel(CommandLevel *str);
extern void PrintCommandLevel(CommandLevel *eleptr);
extern void FreeCommandLevel(CommandLevel *eleptr);
extern void *AllocCommandLevel();
extern void WriteBinCommandLevel(CommandLevel *eleptr, DbaseLinkedList *file);
extern INT ReadBinCommandLevel(CommandLevel *eleptr, DbaseLinkedList *file);
extern void xdr_CommandLevel(XDR *stream, char **eleptr);
extern void CopyFullCommandLevel(CommandLevel *newstruct, CommandLevel *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:301:StringBuffer

               BufferLeft --(INT) The number of bytes left in the buffer
             OutputBuffer --(STRING) The output buffer
               OutputFile --(FILE) The associated file to print to
*/
typedef struct stringbuffer StringBuffer;
struct stringbuffer {
     INT ID;
     CHAR *Name;
     INT  BufferLeft;
     STRING *OutputBuffer;
     FILE *OutputFile;
     };
#define StringBufferSize sizeof(StringBuffer)
#define AllocateStringBuffer (StringBuffer *) Malloc(StringBufferSize)
#define AllocArrayStringBuffer(n) (StringBuffer *) Calloc(n,StringBufferSize)
#define StringBufferPntrSize sizeof(StringBuffer **)
#define AllocPntrArrayStringBuffer(n) (StringBuffer **) Calloc(n,StringBufferPntrSize)
#define SingCopyStringBuffer(out,in) memcpy(out,in,StringBufferSize)
extern StringBuffer *CreateStringBuffer(StringBuffer *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  BufferLeft,
                                 STRING *OutputBuffer,
                                 FILE *OutputFile);

extern CHAR *GetNameStringBuffer(StringBuffer *str);
extern INT  GetIDStringBuffer(StringBuffer *str);
extern void PrintStringBuffer(StringBuffer *eleptr);
extern void FreeStringBuffer(StringBuffer *eleptr);
extern void *AllocStringBuffer();
extern void WriteBinStringBuffer(StringBuffer *eleptr, DbaseLinkedList *file);
extern INT ReadBinStringBuffer(StringBuffer *eleptr, DbaseLinkedList *file);
extern void xdr_StringBuffer(XDR *stream, char **eleptr);
extern void CopyFullStringBuffer(StringBuffer *newstruct, StringBuffer *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:301:ErrorStatus

                  EStatus --(INT) The Error Status Flag
            ErrorRecovery --(INT) What to do to recover from an error
*/
typedef struct errorstatus ErrorStatus;
struct errorstatus {
     INT ID;
     CHAR *Name;
     INT  EStatus;
     INT  ErrorRecovery;
     };
#define ErrorStatusSize sizeof(ErrorStatus)
#define AllocateErrorStatus (ErrorStatus *) Malloc(ErrorStatusSize)
#define AllocArrayErrorStatus(n) (ErrorStatus *) Calloc(n,ErrorStatusSize)
#define ErrorStatusPntrSize sizeof(ErrorStatus **)
#define AllocPntrArrayErrorStatus(n) (ErrorStatus **) Calloc(n,ErrorStatusPntrSize)
#define SingCopyErrorStatus(out,in) memcpy(out,in,ErrorStatusSize)
extern ErrorStatus *CreateErrorStatus(ErrorStatus *newstruct,
                               INT id,
                               CHAR *name,
                               INT  EStatus,
                               INT  ErrorRecovery);

extern CHAR *GetNameErrorStatus(ErrorStatus *str);
extern INT  GetIDErrorStatus(ErrorStatus *str);
extern void PrintErrorStatus(ErrorStatus *eleptr);
extern void FreeErrorStatus(ErrorStatus *eleptr);
extern void *AllocErrorStatus();
extern void WriteBinErrorStatus(ErrorStatus *eleptr, DbaseLinkedList *file);
extern INT ReadBinErrorStatus(ErrorStatus *eleptr, DbaseLinkedList *file);
extern void xdr_ErrorStatus(XDR *stream, char **eleptr);
extern void CopyFullErrorStatus(ErrorStatus *newstruct, ErrorStatus *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:300:CommandSource

                     File --(FILE) This is the source ASCII file under Batch Mode
                  Command --(CommandReturn) This is the Current Command Line in Batch Mode
                ErrorStat --(ErrorStatus) This is what to do in case of an error
                  Verbose --(INT) This is the level of Verbose printout
              StandardOut --(StringBuffer) This is the standard ASCII out
              ProtocolOut --(StringBuffer) This is the standard ASCII protocol
                 ErrorOut --(StringBuffer)  This is the standard error
*/
typedef struct commandsource CommandSource;
struct commandsource {
     INT ID;
     CHAR *Name;
     FILE *File;
     CommandReturn *Command;
     ErrorStatus *ErrorStat;
     INT  Verbose;
     StringBuffer *StandardOut;
     StringBuffer *ProtocolOut;
     StringBuffer *ErrorOut;
     };
#define CommandSourceSize sizeof(CommandSource)
#define AllocateCommandSource (CommandSource *) Malloc(CommandSourceSize)
#define AllocArrayCommandSource(n) (CommandSource *) Calloc(n,CommandSourceSize)
#define CommandSourcePntrSize sizeof(CommandSource **)
#define AllocPntrArrayCommandSource(n) (CommandSource **) Calloc(n,CommandSourcePntrSize)
#define SingCopyCommandSource(out,in) memcpy(out,in,CommandSourceSize)
extern CommandSource *CreateCommandSource(CommandSource *newstruct,
                                   INT id,
                                   CHAR *name,
                                   FILE *File,
                                   CommandReturn *Command,
                                   ErrorStatus *ErrorStat,
                                   INT  Verbose,
                                   StringBuffer *StandardOut,
                                   StringBuffer *ProtocolOut,
                                   StringBuffer *ErrorOut);

extern CHAR *GetNameCommandSource(CommandSource *str);
extern INT  GetIDCommandSource(CommandSource *str);
extern void PrintCommandSource(CommandSource *eleptr);
extern void FreeCommandSource(CommandSource *eleptr);
extern void *AllocCommandSource();
extern void WriteBinCommandSource(CommandSource *eleptr, DbaseLinkedList *file);
extern INT ReadBinCommandSource(CommandSource *eleptr, DbaseLinkedList *file);
extern void xdr_CommandSource(XDR *stream, char **eleptr);
extern void CopyFullCommandSource(CommandSource *newstruct, CommandSource *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:302:FunctionList

        NumberOfFunctions --(INT) The number of functions in the list
                 Function --(FunctionInfo) The List of Functions
*/
typedef struct functionlist FunctionList;
struct functionlist {
     INT ID;
     CHAR *Name;
     INT  NumberOfFunctions;
     FunctionInfo *Function;
     };
#define FunctionListSize sizeof(FunctionList)
#define AllocateFunctionList (FunctionList *) Malloc(FunctionListSize)
#define AllocArrayFunctionList(n) (FunctionList *) Calloc(n,FunctionListSize)
#define FunctionListPntrSize sizeof(FunctionList **)
#define AllocPntrArrayFunctionList(n) (FunctionList **) Calloc(n,FunctionListPntrSize)
#define SingCopyFunctionList(out,in) memcpy(out,in,FunctionListSize)
extern FunctionList *CreateFunctionList(FunctionList *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfFunctions,
                                 FunctionInfo *Function);

extern CHAR *GetNameFunctionList(FunctionList *str);
extern INT  GetIDFunctionList(FunctionList *str);
extern void PrintFunctionList(FunctionList *eleptr);
extern void FreeFunctionList(FunctionList *eleptr);
extern void *AllocFunctionList();
extern void WriteBinFunctionList(FunctionList *eleptr, DbaseLinkedList *file);
extern INT ReadBinFunctionList(FunctionList *eleptr, DbaseLinkedList *file);
extern void xdr_FunctionList(XDR *stream, char **eleptr);
extern void CopyFullFunctionList(FunctionList *newstruct, FunctionList *oldstruct);
/*------------------------------------------*/
/*   Structures for Commands Run Version   */
/* Structure:301:CommandMaster

                   Source --(CommandSource) This is Input Source Information
                 Commands --(CommandInfo) This is the main command tree
                Functions --(FunctionList) This are the list of available functions
                   Levels --(CommandLevel) These are the levels of Command
           MasterProgInfo --(VOID) This is the Master Structure for the Program Data
                Utilities --(CommandInfo) These are the Utility (fixed) Commands
                 AliasSet --(AliasArray)   The set of aliases
*/
typedef struct commandmaster CommandMaster;
struct commandmaster {
     INT ID;
     CHAR *Name;
     CommandSource *Source;
     CommandInfo *Commands;
     FunctionList *Functions;
     CommandLevel *Levels;
     VOID  MasterProgInfo;
     CommandInfo *Utilities;
     AliasArray *AliasSet;
     };
#define CommandMasterSize sizeof(CommandMaster)
#define AllocateCommandMaster (CommandMaster *) Malloc(CommandMasterSize)
#define AllocArrayCommandMaster(n) (CommandMaster *) Calloc(n,CommandMasterSize)
#define CommandMasterPntrSize sizeof(CommandMaster **)
#define AllocPntrArrayCommandMaster(n) (CommandMaster **) Calloc(n,CommandMasterPntrSize)
#define SingCopyCommandMaster(out,in) memcpy(out,in,CommandMasterSize)
extern CommandMaster *CreateCommandMaster(CommandMaster *newstruct,
                                   INT id,
                                   CHAR *name,
                                   CommandSource *Source,
                                   CommandInfo *Commands,
                                   FunctionList *Functions,
                                   CommandLevel *Levels,
                                   VOID  MasterProgInfo,
                                   CommandInfo *Utilities,
                                   AliasArray *AliasSet);

extern CHAR *GetNameCommandMaster(CommandMaster *str);
extern INT  GetIDCommandMaster(CommandMaster *str);
extern void PrintCommandMaster(CommandMaster *eleptr);
extern void FreeCommandMaster(CommandMaster *eleptr);
extern void *AllocCommandMaster();
extern void WriteBinCommandMaster(CommandMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinCommandMaster(CommandMaster *eleptr, DbaseLinkedList *file);
extern void xdr_CommandMaster(XDR *stream, char **eleptr);
extern void CopyFullCommandMaster(CommandMaster *newstruct, CommandMaster *oldstruct);
