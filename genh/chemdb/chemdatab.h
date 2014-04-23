/*------------------------------------------*/
/*   Chemisty Database Structures   */
/* Structure:100:ChemDBConstants

              DBDirectory --(STRING) The database directory
                DBMolRoot --(STRING) The Molecule Database Root
       DBSubstructureRoot --(STRING) The Substructure Database Root
                DBRxnRoot --(STRING) The Reaction Database Root
          DBDataDirectory --(STRING) The data directory (ex. MolFiles)
            DBDataMolRoot --(STRING) The Molecule Database Root
            DBDataRxnRoot --(STRING) The Reaction Database Root
*/
typedef struct chemdbconstants ChemDBConstants;
struct chemdbconstants {
     INT ID;
     CHAR *Name;
     STRING *DBDirectory;
     STRING *DBMolRoot;
     STRING *DBSubstructureRoot;
     STRING *DBRxnRoot;
     STRING *DBDataDirectory;
     STRING *DBDataMolRoot;
     STRING *DBDataRxnRoot;
     };
#define ChemDBConstantsSize sizeof(ChemDBConstants)
#define AllocateChemDBConstants (ChemDBConstants *) Malloc(ChemDBConstantsSize)
#define AllocArrayChemDBConstants(n) (ChemDBConstants *) Calloc(n,ChemDBConstantsSize)
#define ChemDBConstantsPntrSize sizeof(ChemDBConstants **)
#define AllocPntrArrayChemDBConstants(n) (ChemDBConstants **) Calloc(n,ChemDBConstantsPntrSize)
#define SingCopyChemDBConstants(out,in) memcpy(out,in,ChemDBConstantsSize)
extern ChemDBConstants *CreateChemDBConstants(ChemDBConstants *newstruct,
                                       INT id,
                                       CHAR *name,
                                       STRING *DBDirectory,
                                       STRING *DBMolRoot,
                                       STRING *DBSubstructureRoot,
                                       STRING *DBRxnRoot,
                                       STRING *DBDataDirectory,
                                       STRING *DBDataMolRoot,
                                       STRING *DBDataRxnRoot);

extern CHAR *GetNameChemDBConstants(ChemDBConstants *str);
extern INT  GetIDChemDBConstants(ChemDBConstants *str);
extern void PrintChemDBConstants(ChemDBConstants *eleptr);
extern void FreeChemDBConstants(ChemDBConstants *eleptr);
extern void *AllocChemDBConstants();
extern void WriteBinChemDBConstants(ChemDBConstants *eleptr, DbaseLinkedList *file);
extern INT ReadBinChemDBConstants(ChemDBConstants *eleptr, DbaseLinkedList *file);
extern void xdr_ChemDBConstants(XDR *stream, char **eleptr);
extern void CopyFullChemDBConstants(ChemDBConstants *newstruct, ChemDBConstants *oldstruct);
/*------------------------------------------*/
/*   Chemisty Database Structures   */
/* Structure:100:ChemDBMaster

             DatabaseInfo --(DbaseMaster) The set of databases
                Constants --(ChemDBConstants) Database Constants
*/
typedef struct chemdbmaster ChemDBMaster;
struct chemdbmaster {
     INT ID;
     CHAR *Name;
     DbaseMaster *DatabaseInfo;
     ChemDBConstants *Constants;
     };
#define ChemDBMasterSize sizeof(ChemDBMaster)
#define AllocateChemDBMaster (ChemDBMaster *) Malloc(ChemDBMasterSize)
#define AllocArrayChemDBMaster(n) (ChemDBMaster *) Calloc(n,ChemDBMasterSize)
#define ChemDBMasterPntrSize sizeof(ChemDBMaster **)
#define AllocPntrArrayChemDBMaster(n) (ChemDBMaster **) Calloc(n,ChemDBMasterPntrSize)
#define SingCopyChemDBMaster(out,in) memcpy(out,in,ChemDBMasterSize)
extern ChemDBMaster *CreateChemDBMaster(ChemDBMaster *newstruct,
                                 INT id,
                                 CHAR *name,
                                 DbaseMaster *DatabaseInfo,
                                 ChemDBConstants *Constants);

extern CHAR *GetNameChemDBMaster(ChemDBMaster *str);
extern INT  GetIDChemDBMaster(ChemDBMaster *str);
extern void PrintChemDBMaster(ChemDBMaster *eleptr);
extern void FreeChemDBMaster(ChemDBMaster *eleptr);
extern void *AllocChemDBMaster();
extern void WriteBinChemDBMaster(ChemDBMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinChemDBMaster(ChemDBMaster *eleptr, DbaseLinkedList *file);
extern void xdr_ChemDBMaster(XDR *stream, char **eleptr);
extern void CopyFullChemDBMaster(ChemDBMaster *newstruct, ChemDBMaster *oldstruct);
