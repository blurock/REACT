/*------------------------------------------*/
/*   Database Structures   */
/* Structure:101:DbaseKeyword

                     Size --(INT) The size of the Keyword
                  KeyWord --(CHAR) The keyword itself
*/
typedef struct dbasekeyword DbaseKeyword;
struct dbasekeyword {
     INT ID;
     CHAR *Name;
     INT  Size;
     CHAR *KeyWord;
     };
#define DbaseKeywordSize sizeof(DbaseKeyword)
#define AllocateDbaseKeyword (DbaseKeyword *) Malloc(DbaseKeywordSize)
#define AllocArrayDbaseKeyword(n) (DbaseKeyword *) Calloc(n,DbaseKeywordSize)
#define DbaseKeywordPntrSize sizeof(DbaseKeyword **)
#define AllocPntrArrayDbaseKeyword(n) (DbaseKeyword **) Calloc(n,DbaseKeywordPntrSize)
#define SingCopyDbaseKeyword(out,in) memcpy(out,in,DbaseKeywordSize)
extern DbaseKeyword *CreateDbaseKeyword(DbaseKeyword *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  Size,
                                 CHAR *KeyWord);

extern CHAR *GetNameDbaseKeyword(DbaseKeyword *str);
extern INT  GetIDDbaseKeyword(DbaseKeyword *str);
extern void PrintDbaseKeyword(DbaseKeyword *eleptr);
extern void FreeDbaseKeyword(DbaseKeyword *eleptr);
extern void *AllocDbaseKeyword();
extern void WriteBinDbaseKeyword(DbaseKeyword *eleptr, DbaseLinkedList *file);
extern INT ReadBinDbaseKeyword(DbaseKeyword *eleptr, DbaseLinkedList *file);
extern void xdr_DbaseKeyword(XDR *stream, char **eleptr);
extern void CopyFullDbaseKeyword(DbaseKeyword *newstruct, DbaseKeyword *oldstruct);
/*------------------------------------------*/
/*   Database Structures   */
/* Structure:102:SingleSearchKey

                    DBKey --(DbaseKeyword) The Database key
                   Search --(DbaseKeyword) The Search Keyword
*/
typedef struct singlesearchkey SingleSearchKey;
struct singlesearchkey {
     INT ID;
     CHAR *Name;
     DbaseKeyword *DBKey;
     DbaseKeyword *Search;
     };
#define SingleSearchKeySize sizeof(SingleSearchKey)
#define AllocateSingleSearchKey (SingleSearchKey *) Malloc(SingleSearchKeySize)
#define AllocArraySingleSearchKey(n) (SingleSearchKey *) Calloc(n,SingleSearchKeySize)
#define SingleSearchKeyPntrSize sizeof(SingleSearchKey **)
#define AllocPntrArraySingleSearchKey(n) (SingleSearchKey **) Calloc(n,SingleSearchKeyPntrSize)
#define SingCopySingleSearchKey(out,in) memcpy(out,in,SingleSearchKeySize)
extern SingleSearchKey *CreateSingleSearchKey(SingleSearchKey *newstruct,
                                       INT id,
                                       CHAR *name,
                                       DbaseKeyword *DBKey,
                                       DbaseKeyword *Search);

extern CHAR *GetNameSingleSearchKey(SingleSearchKey *str);
extern INT  GetIDSingleSearchKey(SingleSearchKey *str);
extern void PrintSingleSearchKey(SingleSearchKey *eleptr);
extern void FreeSingleSearchKey(SingleSearchKey *eleptr);
extern void *AllocSingleSearchKey();
extern void WriteBinSingleSearchKey(SingleSearchKey *eleptr, DbaseLinkedList *file);
extern INT ReadBinSingleSearchKey(SingleSearchKey *eleptr, DbaseLinkedList *file);
extern void xdr_SingleSearchKey(XDR *stream, char **eleptr);
extern void CopyFullSingleSearchKey(SingleSearchKey *newstruct, SingleSearchKey *oldstruct);
/*------------------------------------------*/
/*   Database Structures   */
/* Structure:103:SetOfSearchKeys

     NumberOfAllocatedKeys --(INT) The allocated number of search keys
             NumberOfKeys --(INT) The number of filled in keys
                     Keys --(SingleSearchKey) The keys 
*/
typedef struct setofsearchkeys SetOfSearchKeys;
struct setofsearchkeys {
     INT ID;
     CHAR *Name;
     INT  NumberOfAllocatedKeys;
     INT  NumberOfKeys;
     SingleSearchKey *Keys;
     };
#define SetOfSearchKeysSize sizeof(SetOfSearchKeys)
#define AllocateSetOfSearchKeys (SetOfSearchKeys *) Malloc(SetOfSearchKeysSize)
#define AllocArraySetOfSearchKeys(n) (SetOfSearchKeys *) Calloc(n,SetOfSearchKeysSize)
#define SetOfSearchKeysPntrSize sizeof(SetOfSearchKeys **)
#define AllocPntrArraySetOfSearchKeys(n) (SetOfSearchKeys **) Calloc(n,SetOfSearchKeysPntrSize)
#define SingCopySetOfSearchKeys(out,in) memcpy(out,in,SetOfSearchKeysSize)
extern SetOfSearchKeys *CreateSetOfSearchKeys(SetOfSearchKeys *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfAllocatedKeys,
                                       INT  NumberOfKeys,
                                       SingleSearchKey *Keys);

extern CHAR *GetNameSetOfSearchKeys(SetOfSearchKeys *str);
extern INT  GetIDSetOfSearchKeys(SetOfSearchKeys *str);
extern void PrintSetOfSearchKeys(SetOfSearchKeys *eleptr);
extern void FreeSetOfSearchKeys(SetOfSearchKeys *eleptr);
extern void *AllocSetOfSearchKeys();
extern void WriteBinSetOfSearchKeys(SetOfSearchKeys *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfSearchKeys(SetOfSearchKeys *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfSearchKeys(XDR *stream, char **eleptr);
extern void CopyFullSetOfSearchKeys(SetOfSearchKeys *newstruct, SetOfSearchKeys *oldstruct);
/*------------------------------------------*/
/*   Database Structures   */
/* Structure:104:SearchKeyInfo

        InitialAllocation --(INT) The initial number of keys allocated
      AllocationIncrement --(INT) The incremental allocation
                     Keys --(SetOfSearchKeys) The set of keys
                InsertKey --(FUNCTION) Routine to fill in keyword
*/
typedef struct searchkeyinfo SearchKeyInfo;
struct searchkeyinfo {
     INT ID;
     CHAR *Name;
     INT  InitialAllocation;
     INT  AllocationIncrement;
     SetOfSearchKeys *Keys;
     void  (*InsertKey)();
     };
#define SearchKeyInfoSize sizeof(SearchKeyInfo)
#define AllocateSearchKeyInfo (SearchKeyInfo *) Malloc(SearchKeyInfoSize)
#define AllocArraySearchKeyInfo(n) (SearchKeyInfo *) Calloc(n,SearchKeyInfoSize)
#define SearchKeyInfoPntrSize sizeof(SearchKeyInfo **)
#define AllocPntrArraySearchKeyInfo(n) (SearchKeyInfo **) Calloc(n,SearchKeyInfoPntrSize)
#define SingCopySearchKeyInfo(out,in) memcpy(out,in,SearchKeyInfoSize)
extern SearchKeyInfo *CreateSearchKeyInfo(SearchKeyInfo *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  InitialAllocation,
                                   INT  AllocationIncrement,
                                   SetOfSearchKeys *Keys,
                                   void  (*InsertKey)());

extern CHAR *GetNameSearchKeyInfo(SearchKeyInfo *str);
extern INT  GetIDSearchKeyInfo(SearchKeyInfo *str);
extern void PrintSearchKeyInfo(SearchKeyInfo *eleptr);
extern void FreeSearchKeyInfo(SearchKeyInfo *eleptr);
extern void *AllocSearchKeyInfo();
extern void WriteBinSearchKeyInfo(SearchKeyInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinSearchKeyInfo(SearchKeyInfo *eleptr, DbaseLinkedList *file);
extern void xdr_SearchKeyInfo(XDR *stream, char **eleptr);
extern void CopyFullSearchKeyInfo(SearchKeyInfo *newstruct, SearchKeyInfo *oldstruct);
/*------------------------------------------*/
/*   Database Structures   */
/* Structure:105:SetOfSearchKeyTypes

     NumberOfAllocatedKeys --(INT) The number of Allocated Keys
         NumberOfKeyTypes --(INT) The Number of Keys Types
                 KeyTypes --(SearchKeyInfo) The set of key types
*/
typedef struct setofsearchkeytypes SetOfSearchKeyTypes;
struct setofsearchkeytypes {
     INT ID;
     CHAR *Name;
     INT  NumberOfAllocatedKeys;
     INT  NumberOfKeyTypes;
     SearchKeyInfo *KeyTypes;
     };
#define SetOfSearchKeyTypesSize sizeof(SetOfSearchKeyTypes)
#define AllocateSetOfSearchKeyTypes (SetOfSearchKeyTypes *) Malloc(SetOfSearchKeyTypesSize)
#define AllocArraySetOfSearchKeyTypes(n) (SetOfSearchKeyTypes *) Calloc(n,SetOfSearchKeyTypesSize)
#define SetOfSearchKeyTypesPntrSize sizeof(SetOfSearchKeyTypes **)
#define AllocPntrArraySetOfSearchKeyTypes(n) (SetOfSearchKeyTypes **) Calloc(n,SetOfSearchKeyTypesPntrSize)
#define SingCopySetOfSearchKeyTypes(out,in) memcpy(out,in,SetOfSearchKeyTypesSize)
extern SetOfSearchKeyTypes *CreateSetOfSearchKeyTypes(SetOfSearchKeyTypes *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfAllocatedKeys,
                                               INT  NumberOfKeyTypes,
                                               SearchKeyInfo *KeyTypes);

extern CHAR *GetNameSetOfSearchKeyTypes(SetOfSearchKeyTypes *str);
extern INT  GetIDSetOfSearchKeyTypes(SetOfSearchKeyTypes *str);
extern void PrintSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr);
extern void FreeSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr);
extern void *AllocSetOfSearchKeyTypes();
extern void WriteBinSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfSearchKeyTypes(XDR *stream, char **eleptr);
extern void CopyFullSetOfSearchKeyTypes(SetOfSearchKeyTypes *newstruct, SetOfSearchKeyTypes *oldstruct);
/*------------------------------------------*/
/*   Database Structures   */
/* Structure:101:DataBaseInformation

             FilenameRoot --(STRING) The filename root
                Directory --(STRING) The Directory of the database
          WriteConversion --(FUNCTION) Element Write conversion
           ReadConversion --(FUNCTION) Element Read conversion
                     File --(VOID) Database File Information
                     Keys --(SetOfSearchKeyTypes) Database Key Information
          AllocateElement --(FUNCTION) The allocate element routine
              FreeElement --(FUNCTION) Routine to Free element
*/
typedef struct databaseinformation DataBaseInformation;
struct databaseinformation {
     INT ID;
     CHAR *Name;
     STRING *FilenameRoot;
     STRING *Directory;
     void  (*WriteConversion)();
     INT  (*ReadConversion)();
     VOID  File;
     SetOfSearchKeyTypes *Keys;
     VOID  (*AllocateElement)();
     void  (*FreeElement)();
     };
#define DataBaseInformationSize sizeof(DataBaseInformation)
#define AllocateDataBaseInformation (DataBaseInformation *) Malloc(DataBaseInformationSize)
#define AllocArrayDataBaseInformation(n) (DataBaseInformation *) Calloc(n,DataBaseInformationSize)
#define DataBaseInformationPntrSize sizeof(DataBaseInformation **)
#define AllocPntrArrayDataBaseInformation(n) (DataBaseInformation **) Calloc(n,DataBaseInformationPntrSize)
#define SingCopyDataBaseInformation(out,in) memcpy(out,in,DataBaseInformationSize)
extern DataBaseInformation *CreateDataBaseInformation(DataBaseInformation *newstruct,
                                               INT id,
                                               CHAR *name,
                                               STRING *FilenameRoot,
                                               STRING *Directory,
                                               void  (*WriteConversion)(),
                                               INT  (*ReadConversion)(),
                                               VOID  File,
                                               SetOfSearchKeyTypes *Keys,
                                               VOID  (*AllocateElement)(),
                                               void  (*FreeElement)());

extern CHAR *GetNameDataBaseInformation(DataBaseInformation *str);
extern INT  GetIDDataBaseInformation(DataBaseInformation *str);
extern void PrintDataBaseInformation(DataBaseInformation *eleptr);
extern void FreeDataBaseInformation(DataBaseInformation *eleptr);
extern void *AllocDataBaseInformation();
extern void WriteBinDataBaseInformation(DataBaseInformation *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataBaseInformation(DataBaseInformation *eleptr, DbaseLinkedList *file);
extern void xdr_DataBaseInformation(XDR *stream, char **eleptr);
extern void CopyFullDataBaseInformation(DataBaseInformation *newstruct, DataBaseInformation *oldstruct);
/*------------------------------------------*/
/*   Database Structures   */
/* Structure:100:DbaseMaster

        NumberOfDatabases --(INT) The number of databases
                Databases --(DataBaseInformation) The set of databases
*/
typedef struct dbasemaster DbaseMaster;
struct dbasemaster {
     INT ID;
     CHAR *Name;
     INT  NumberOfDatabases;
     DataBaseInformation *Databases;
     };
#define DbaseMasterSize sizeof(DbaseMaster)
#define AllocateDbaseMaster (DbaseMaster *) Malloc(DbaseMasterSize)
#define AllocArrayDbaseMaster(n) (DbaseMaster *) Calloc(n,DbaseMasterSize)
#define DbaseMasterPntrSize sizeof(DbaseMaster **)
#define AllocPntrArrayDbaseMaster(n) (DbaseMaster **) Calloc(n,DbaseMasterPntrSize)
#define SingCopyDbaseMaster(out,in) memcpy(out,in,DbaseMasterSize)
extern DbaseMaster *CreateDbaseMaster(DbaseMaster *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfDatabases,
                               DataBaseInformation *Databases);

extern CHAR *GetNameDbaseMaster(DbaseMaster *str);
extern INT  GetIDDbaseMaster(DbaseMaster *str);
extern void PrintDbaseMaster(DbaseMaster *eleptr);
extern void FreeDbaseMaster(DbaseMaster *eleptr);
extern void *AllocDbaseMaster();
extern void WriteBinDbaseMaster(DbaseMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinDbaseMaster(DbaseMaster *eleptr, DbaseLinkedList *file);
extern void xdr_DbaseMaster(XDR *stream, char **eleptr);
extern void CopyFullDbaseMaster(DbaseMaster *newstruct, DbaseMaster *oldstruct);
