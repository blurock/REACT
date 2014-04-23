/*------------------------------------------*/
/*   Molecule Read Lists   */
/* Structure:2:ReadInMolecule

                     Rest --(STRING) The rest of the line (Auxillary information)
               Properties --(ASCIIProperties) The set of properties (if applicaable) following the line
*/
typedef struct readinmolecule ReadInMolecule;
struct readinmolecule {
     INT ID;
     CHAR *Name;
     STRING *Rest;
     ASCIIProperties *Properties;
     };
#define ReadInMoleculeSize sizeof(ReadInMolecule)
#define AllocateReadInMolecule (ReadInMolecule *) Malloc(ReadInMoleculeSize)
#define AllocArrayReadInMolecule(n) (ReadInMolecule *) Calloc(n,ReadInMoleculeSize)
#define ReadInMoleculePntrSize sizeof(ReadInMolecule **)
#define AllocPntrArrayReadInMolecule(n) (ReadInMolecule **) Calloc(n,ReadInMoleculePntrSize)
#define SingCopyReadInMolecule(out,in) memcpy(out,in,ReadInMoleculeSize)
extern ReadInMolecule *CreateReadInMolecule(ReadInMolecule *newstruct,
                                     INT id,
                                     CHAR *name,
                                     STRING *Rest,
                                     ASCIIProperties *Properties);

extern CHAR *GetNameReadInMolecule(ReadInMolecule *str);
extern INT  GetIDReadInMolecule(ReadInMolecule *str);
extern void PrintReadInMolecule(ReadInMolecule *eleptr);
extern void FreeReadInMolecule(ReadInMolecule *eleptr);
extern void *AllocReadInMolecule();
extern void WriteBinReadInMolecule(ReadInMolecule *eleptr, DbaseLinkedList *file);
extern INT ReadBinReadInMolecule(ReadInMolecule *eleptr, DbaseLinkedList *file);
extern void xdr_ReadInMolecule(XDR *stream, char **eleptr);
extern void CopyFullReadInMolecule(ReadInMolecule *newstruct, ReadInMolecule *oldstruct);
/*------------------------------------------*/
/*   Molecule Read Lists   */
/* Structure:3:ReadInMoleculeSet

        NumberOfMolecules --(INT) The number of molecules in the list
                Molecules --(ReadInMolecule) The set of molecules
*/
typedef struct readinmoleculeset ReadInMoleculeSet;
struct readinmoleculeset {
     INT ID;
     CHAR *Name;
     INT  NumberOfMolecules;
     ReadInMolecule *Molecules;
     };
#define ReadInMoleculeSetSize sizeof(ReadInMoleculeSet)
#define AllocateReadInMoleculeSet (ReadInMoleculeSet *) Malloc(ReadInMoleculeSetSize)
#define AllocArrayReadInMoleculeSet(n) (ReadInMoleculeSet *) Calloc(n,ReadInMoleculeSetSize)
#define ReadInMoleculeSetPntrSize sizeof(ReadInMoleculeSet **)
#define AllocPntrArrayReadInMoleculeSet(n) (ReadInMoleculeSet **) Calloc(n,ReadInMoleculeSetPntrSize)
#define SingCopyReadInMoleculeSet(out,in) memcpy(out,in,ReadInMoleculeSetSize)
extern ReadInMoleculeSet *CreateReadInMoleculeSet(ReadInMoleculeSet *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfMolecules,
                                           ReadInMolecule *Molecules);

extern CHAR *GetNameReadInMoleculeSet(ReadInMoleculeSet *str);
extern INT  GetIDReadInMoleculeSet(ReadInMoleculeSet *str);
extern void PrintReadInMoleculeSet(ReadInMoleculeSet *eleptr);
extern void FreeReadInMoleculeSet(ReadInMoleculeSet *eleptr);
extern void *AllocReadInMoleculeSet();
extern void WriteBinReadInMoleculeSet(ReadInMoleculeSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinReadInMoleculeSet(ReadInMoleculeSet *eleptr, DbaseLinkedList *file);
extern void xdr_ReadInMoleculeSet(XDR *stream, char **eleptr);
extern void CopyFullReadInMoleculeSet(ReadInMoleculeSet *newstruct, ReadInMoleculeSet *oldstruct);
