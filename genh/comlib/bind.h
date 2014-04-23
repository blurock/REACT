/*------------------------------------------*/
/*   Binding Together Master Data Structures   */
/* Structure:10:BindStructure

     MaxNumberOfBoundStructures --(INT) The Maximum Number of Structures to be bound
     NumberOfBoundStructures --(INT) The Number of Structures to be bound
               Structures --(VOID) The Master Structures 
                    Flags --(INT) The List of Corresponding Flags for the Bound Structures
*/
typedef struct bindstructure BindStructure;
struct bindstructure {
     INT ID;
     CHAR *Name;
     INT  MaxNumberOfBoundStructures;
     INT  NumberOfBoundStructures;
     VOID *Structures;
     INT *Flags;
     };
#define BindStructureSize sizeof(BindStructure)
#define AllocateBindStructure (BindStructure *) Malloc(BindStructureSize)
#define AllocArrayBindStructure(n) (BindStructure *) Calloc(n,BindStructureSize)
#define BindStructurePntrSize sizeof(BindStructure **)
#define AllocPntrArrayBindStructure(n) (BindStructure **) Calloc(n,BindStructurePntrSize)
#define SingCopyBindStructure(out,in) memcpy(out,in,BindStructureSize)
extern BindStructure *CreateBindStructure(BindStructure *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  MaxNumberOfBoundStructures,
                                   INT  NumberOfBoundStructures,
                                   VOID *Structures,
                                   INT *Flags);

extern CHAR *GetNameBindStructure(BindStructure *str);
extern INT  GetIDBindStructure(BindStructure *str);
extern void PrintBindStructure(BindStructure *eleptr);
extern void FreeBindStructure(BindStructure *eleptr);
extern void *AllocBindStructure();
extern void WriteBinBindStructure(BindStructure *eleptr, DbaseLinkedList *file);
extern INT ReadBinBindStructure(BindStructure *eleptr, DbaseLinkedList *file);
extern void xdr_BindStructure(XDR *stream, char **eleptr);
extern void CopyFullBindStructure(BindStructure *newstruct, BindStructure *oldstruct);
