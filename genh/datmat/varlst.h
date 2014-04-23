/*------------------------------------------*/
/*   Structures for varlst.c   */
/* Structure:20:VarInfo

                   Length --(INT) The length of the information string
                     Info --(CHAR) The Information String
*/
typedef struct info VarInfo;
struct info {
     INT ID;
     CHAR *Name;
     INT  Length;
     CHAR *Info;
     };
#define VarInfoSize sizeof(VarInfo)
#define AllocateVarInfo (VarInfo *) Malloc(VarInfoSize)
#define AllocArrayVarInfo(n) (VarInfo *) Calloc(n,VarInfoSize)
#define VarInfoPntrSize sizeof(VarInfo **)
#define AllocPntrArrayVarInfo(n) (VarInfo **) Calloc(n,VarInfoPntrSize)
#define SingCopyVarInfo(out,in) memcpy(out,in,VarInfoSize)
extern VarInfo *CreateVarInfo(VarInfo *newstruct,
                       INT id,
                       CHAR *name,
                       INT  Length,
                       CHAR *Info);

extern CHAR *GetNameVarInfo(VarInfo *str);
extern INT  GetIDVarInfo(VarInfo *str);
extern void PrintVarInfo(VarInfo *eleptr);
extern void FreeVarInfo(VarInfo *eleptr);
extern void *AllocVarInfo();
extern void WriteBinVarInfo(VarInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinVarInfo(VarInfo *eleptr, DbaseLinkedList *file);
extern void xdr_VarInfo(XDR *stream, char **eleptr);
extern void CopyFullVarInfo(VarInfo *newstruct, VarInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for varlst.c   */
/* Structure:21:VarName

                   Length --(INT) The length of the name string
                 Variable --(CHAR) The Name 
*/
typedef struct namevar VarName;
struct namevar {
     INT ID;
     CHAR *Name;
     INT  Length;
     CHAR *Variable;
     };
#define VarNameSize sizeof(VarName)
#define AllocateVarName (VarName *) Malloc(VarNameSize)
#define AllocArrayVarName(n) (VarName *) Calloc(n,VarNameSize)
#define VarNamePntrSize sizeof(VarName **)
#define AllocPntrArrayVarName(n) (VarName **) Calloc(n,VarNamePntrSize)
#define SingCopyVarName(out,in) memcpy(out,in,VarNameSize)
extern VarName *CreateVarName(VarName *newstruct,
                       INT id,
                       CHAR *name,
                       INT  Length,
                       CHAR *Variable);

extern CHAR *GetNameVarName(VarName *str);
extern INT  GetIDVarName(VarName *str);
extern void PrintVarName(VarName *eleptr);
extern void FreeVarName(VarName *eleptr);
extern void *AllocVarName();
extern void WriteBinVarName(VarName *eleptr, DbaseLinkedList *file);
extern INT ReadBinVarName(VarName *eleptr, DbaseLinkedList *file);
extern void xdr_VarName(XDR *stream, char **eleptr);
extern void CopyFullVarName(VarName *newstruct, VarName *oldstruct);
/*------------------------------------------*/
/*   Structures for varlst.c   */
/* Structure:22:VarNames

                 Variable --(VarName) The Variable Name
                   Number --(INT) The Variable Number
              Information --(VarInfo) The Corresponding Information
*/
typedef struct varnames VarNames;
struct varnames {
     INT ID;
     CHAR *Name;
     VarName *Variable;
     INT  Number;
     VarInfo *Information;
     };
#define VarNamesSize sizeof(VarNames)
#define AllocateVarNames (VarNames *) Malloc(VarNamesSize)
#define AllocArrayVarNames(n) (VarNames *) Calloc(n,VarNamesSize)
#define VarNamesPntrSize sizeof(VarNames **)
#define AllocPntrArrayVarNames(n) (VarNames **) Calloc(n,VarNamesPntrSize)
#define SingCopyVarNames(out,in) memcpy(out,in,VarNamesSize)
extern VarNames *CreateVarNames(VarNames *newstruct,
                         INT id,
                         CHAR *name,
                         VarName *Variable,
                         INT  Number,
                         VarInfo *Information);

extern CHAR *GetNameVarNames(VarNames *str);
extern INT  GetIDVarNames(VarNames *str);
extern void PrintVarNames(VarNames *eleptr);
extern void FreeVarNames(VarNames *eleptr);
extern void *AllocVarNames();
extern void WriteBinVarNames(VarNames *eleptr, DbaseLinkedList *file);
extern INT ReadBinVarNames(VarNames *eleptr, DbaseLinkedList *file);
extern void xdr_VarNames(XDR *stream, char **eleptr);
extern void CopyFullVarNames(VarNames *newstruct, VarNames *oldstruct);
/*------------------------------------------*/
/*   Structures for varlst.c   */
/* Structure:23:SystemVariableList

        NumberOfVariables --(INT) The Number of Variables
                Variables --(VarNames) The variable information
*/
typedef struct sysvarlst SystemVariableList;
struct sysvarlst {
     INT ID;
     CHAR *Name;
     INT  NumberOfVariables;
     VarNames *Variables;
     };
#define SystemVariableListSize sizeof(SystemVariableList)
#define AllocateSystemVariableList (SystemVariableList *) Malloc(SystemVariableListSize)
#define AllocArraySystemVariableList(n) (SystemVariableList *) Calloc(n,SystemVariableListSize)
#define SystemVariableListPntrSize sizeof(SystemVariableList **)
#define AllocPntrArraySystemVariableList(n) (SystemVariableList **) Calloc(n,SystemVariableListPntrSize)
#define SingCopySystemVariableList(out,in) memcpy(out,in,SystemVariableListSize)
extern SystemVariableList *CreateSystemVariableList(SystemVariableList *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfVariables,
                                             VarNames *Variables);

extern CHAR *GetNameSystemVariableList(SystemVariableList *str);
extern INT  GetIDSystemVariableList(SystemVariableList *str);
extern void PrintSystemVariableList(SystemVariableList *eleptr);
extern void FreeSystemVariableList(SystemVariableList *eleptr);
extern void *AllocSystemVariableList();
extern void WriteBinSystemVariableList(SystemVariableList *eleptr, DbaseLinkedList *file);
extern INT ReadBinSystemVariableList(SystemVariableList *eleptr, DbaseLinkedList *file);
extern void xdr_SystemVariableList(XDR *stream, char **eleptr);
extern void CopyFullSystemVariableList(SystemVariableList *newstruct, SystemVariableList *oldstruct);
/*------------------------------------------*/
/*   Structures for varlst.c   */
/* Structure:24:SystemVariablePair

              Descriptors --(SystemVariableList) The Descriptor Variables
                    Goals --(SystemVariableList) The Goal Variables
*/
typedef struct systemvariablepair SystemVariablePair;
struct systemvariablepair {
     INT ID;
     CHAR *Name;
     SystemVariableList *Descriptors;
     SystemVariableList *Goals;
     };
#define SystemVariablePairSize sizeof(SystemVariablePair)
#define AllocateSystemVariablePair (SystemVariablePair *) Malloc(SystemVariablePairSize)
#define AllocArraySystemVariablePair(n) (SystemVariablePair *) Calloc(n,SystemVariablePairSize)
#define SystemVariablePairPntrSize sizeof(SystemVariablePair **)
#define AllocPntrArraySystemVariablePair(n) (SystemVariablePair **) Calloc(n,SystemVariablePairPntrSize)
#define SingCopySystemVariablePair(out,in) memcpy(out,in,SystemVariablePairSize)
extern SystemVariablePair *CreateSystemVariablePair(SystemVariablePair *newstruct,
                                             INT id,
                                             CHAR *name,
                                             SystemVariableList *Descriptors,
                                             SystemVariableList *Goals);

extern CHAR *GetNameSystemVariablePair(SystemVariablePair *str);
extern INT  GetIDSystemVariablePair(SystemVariablePair *str);
extern void PrintSystemVariablePair(SystemVariablePair *eleptr);
extern void FreeSystemVariablePair(SystemVariablePair *eleptr);
extern void *AllocSystemVariablePair();
extern void WriteBinSystemVariablePair(SystemVariablePair *eleptr, DbaseLinkedList *file);
extern INT ReadBinSystemVariablePair(SystemVariablePair *eleptr, DbaseLinkedList *file);
extern void xdr_SystemVariablePair(XDR *stream, char **eleptr);
extern void CopyFullSystemVariablePair(SystemVariablePair *newstruct, SystemVariablePair *oldstruct);
