/*------------------------------------------*/
/*   Structure Generation Structures   */
/* Structure:1100:StructuralElement

                  Minimum --(INT) The minimum number of times to appear
                  Maximum --(INT) The maximum number of times to appear
                 Priority --(INT) The priority
*/
typedef struct structuralelement StructuralElement;
struct structuralelement {
     INT ID;
     CHAR *Name;
     INT  Minimum;
     INT  Maximum;
     INT  Priority;
     };
#define StructuralElementSize sizeof(StructuralElement)
#define AllocateStructuralElement (StructuralElement *) Malloc(StructuralElementSize)
#define AllocArrayStructuralElement(n) (StructuralElement *) Calloc(n,StructuralElementSize)
#define StructuralElementPntrSize sizeof(StructuralElement **)
#define AllocPntrArrayStructuralElement(n) (StructuralElement **) Calloc(n,StructuralElementPntrSize)
#define SingCopyStructuralElement(out,in) memcpy(out,in,StructuralElementSize)
extern StructuralElement *CreateStructuralElement(StructuralElement *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  Minimum,
                                           INT  Maximum,
                                           INT  Priority);

extern CHAR *GetNameStructuralElement(StructuralElement *str);
extern INT  GetIDStructuralElement(StructuralElement *str);
extern void PrintStructuralElement(StructuralElement *eleptr);
extern void FreeStructuralElement(StructuralElement *eleptr);
extern void *AllocStructuralElement();
extern void WriteBinStructuralElement(StructuralElement *eleptr, DbaseLinkedList *file);
extern INT ReadBinStructuralElement(StructuralElement *eleptr, DbaseLinkedList *file);
extern void xdr_StructuralElement(XDR *stream, char **eleptr);
extern void CopyFullStructuralElement(StructuralElement *newstruct, StructuralElement *oldstruct);
/*------------------------------------------*/
/*   Structure Generation Structures   */
/* Structure:1101:MoleculeStructureSpecification

         NumberOfElements --(INT) The number of structural elements
       StructuralElements --(StructuralElement) The array of structural elements
*/
typedef struct moleculestructurespecification MoleculeStructureSpecification;
struct moleculestructurespecification {
     INT ID;
     CHAR *Name;
     INT  NumberOfElements;
     StructuralElement *StructuralElements;
     };
#define MoleculeStructureSpecificationSize sizeof(MoleculeStructureSpecification)
#define AllocateMoleculeStructureSpecification (MoleculeStructureSpecification *) Malloc(MoleculeStructureSpecificationSize)
#define AllocArrayMoleculeStructureSpecification(n) (MoleculeStructureSpecification *) Calloc(n,MoleculeStructureSpecificationSize)
#define MoleculeStructureSpecificationPntrSize sizeof(MoleculeStructureSpecification **)
#define AllocPntrArrayMoleculeStructureSpecification(n) (MoleculeStructureSpecification **) Calloc(n,MoleculeStructureSpecificationPntrSize)
#define SingCopyMoleculeStructureSpecification(out,in) memcpy(out,in,MoleculeStructureSpecificationSize)
extern MoleculeStructureSpecification *CreateMoleculeStructureSpecification(MoleculeStructureSpecification *newstruct,
INT id,
CHAR *name,
INT  NumberOfElements,
StructuralElement *StructuralElements);

extern CHAR *GetNameMoleculeStructureSpecification(MoleculeStructureSpecification *str);
extern INT  GetIDMoleculeStructureSpecification(MoleculeStructureSpecification *str);
extern void PrintMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr);
extern void FreeMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr);
extern void *AllocMoleculeStructureSpecification();
extern void WriteBinMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr, DbaseLinkedList *file);
extern INT ReadBinMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr, DbaseLinkedList *file);
extern void xdr_MoleculeStructureSpecification(XDR *stream, char **eleptr);
extern void CopyFullMoleculeStructureSpecification(MoleculeStructureSpecification *newstruct, MoleculeStructureSpecification *oldstruct);
/*------------------------------------------*/
/*   Structure Generation Structures   */
/* Structure:1102:FullStructuralElement

                     Info --(StructuralElement) The Basic Structural information
                 Molecule --(MoleculeInfo) The Molecule information
            MoleculeGraph --(Graph) The Molecule as Graph
              Connections --(DataSubSet) The connections that can be made (relative to graph)
*/
typedef struct fullstructuralelement FullStructuralElement;
struct fullstructuralelement {
     INT ID;
     CHAR *Name;
     StructuralElement *Info;
     MoleculeInfo *Molecule;
     Graph *MoleculeGraph;
     DataSubSet *Connections;
     };
#define FullStructuralElementSize sizeof(FullStructuralElement)
#define AllocateFullStructuralElement (FullStructuralElement *) Malloc(FullStructuralElementSize)
#define AllocArrayFullStructuralElement(n) (FullStructuralElement *) Calloc(n,FullStructuralElementSize)
#define FullStructuralElementPntrSize sizeof(FullStructuralElement **)
#define AllocPntrArrayFullStructuralElement(n) (FullStructuralElement **) Calloc(n,FullStructuralElementPntrSize)
#define SingCopyFullStructuralElement(out,in) memcpy(out,in,FullStructuralElementSize)
extern FullStructuralElement *CreateFullStructuralElement(FullStructuralElement *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   StructuralElement *Info,
                                                   MoleculeInfo *Molecule,
                                                   Graph *MoleculeGraph,
                                                   DataSubSet *Connections);

extern CHAR *GetNameFullStructuralElement(FullStructuralElement *str);
extern INT  GetIDFullStructuralElement(FullStructuralElement *str);
extern void PrintFullStructuralElement(FullStructuralElement *eleptr);
extern void FreeFullStructuralElement(FullStructuralElement *eleptr);
extern void *AllocFullStructuralElement();
extern void WriteBinFullStructuralElement(FullStructuralElement *eleptr, DbaseLinkedList *file);
extern INT ReadBinFullStructuralElement(FullStructuralElement *eleptr, DbaseLinkedList *file);
extern void xdr_FullStructuralElement(XDR *stream, char **eleptr);
extern void CopyFullFullStructuralElement(FullStructuralElement *newstruct, FullStructuralElement *oldstruct);
/*------------------------------------------*/
/*   Structure Generation Structures   */
/* Structure:1103:FullMoleculeSpecification

         NumberOfElements --(INT) The number of structural elements
     FullStructuralElements --(FullStructuralElement) The array of structural elements
             PrioritySets --(DataSubSet) The Priority Set Values
*/
typedef struct fulmoleculespecification FullMoleculeSpecification;
struct fulmoleculespecification {
     INT ID;
     CHAR *Name;
     INT  NumberOfElements;
     FullStructuralElement *FullStructuralElements;
     DataSubSet *PrioritySets;
     };
#define FullMoleculeSpecificationSize sizeof(FullMoleculeSpecification)
#define AllocateFullMoleculeSpecification (FullMoleculeSpecification *) Malloc(FullMoleculeSpecificationSize)
#define AllocArrayFullMoleculeSpecification(n) (FullMoleculeSpecification *) Calloc(n,FullMoleculeSpecificationSize)
#define FullMoleculeSpecificationPntrSize sizeof(FullMoleculeSpecification **)
#define AllocPntrArrayFullMoleculeSpecification(n) (FullMoleculeSpecification **) Calloc(n,FullMoleculeSpecificationPntrSize)
#define SingCopyFullMoleculeSpecification(out,in) memcpy(out,in,FullMoleculeSpecificationSize)
extern FullMoleculeSpecification *CreateFullMoleculeSpecification(FullMoleculeSpecification *newstruct,
INT id,
CHAR *name,
INT  NumberOfElements,
FullStructuralElement *FullStructuralElements,
DataSubSet *PrioritySets);

extern CHAR *GetNameFullMoleculeSpecification(FullMoleculeSpecification *str);
extern INT  GetIDFullMoleculeSpecification(FullMoleculeSpecification *str);
extern void PrintFullMoleculeSpecification(FullMoleculeSpecification *eleptr);
extern void FreeFullMoleculeSpecification(FullMoleculeSpecification *eleptr);
extern void *AllocFullMoleculeSpecification();
extern void WriteBinFullMoleculeSpecification(FullMoleculeSpecification *eleptr, DbaseLinkedList *file);
extern INT ReadBinFullMoleculeSpecification(FullMoleculeSpecification *eleptr, DbaseLinkedList *file);
extern void xdr_FullMoleculeSpecification(XDR *stream, char **eleptr);
extern void CopyFullFullMoleculeSpecification(FullMoleculeSpecification *newstruct, FullMoleculeSpecification *oldstruct);
/*------------------------------------------*/
/*   Structure Generation Structures   */
/* Structure:1200:GenerateStructureMaster

       BasicSpecification --(MoleculeStructureSpecification) The Basic Structure Specification
        FullSpecification --(FullMoleculeSpecification) The Full Filled Specification for molecule generation
*/
typedef struct generatestructuremaster GenerateStructureMaster;
struct generatestructuremaster {
     INT ID;
     CHAR *Name;
     MoleculeStructureSpecification *BasicSpecification;
     FullMoleculeSpecification *FullSpecification;
     };
#define GenerateStructureMasterSize sizeof(GenerateStructureMaster)
#define AllocateGenerateStructureMaster (GenerateStructureMaster *) Malloc(GenerateStructureMasterSize)
#define AllocArrayGenerateStructureMaster(n) (GenerateStructureMaster *) Calloc(n,GenerateStructureMasterSize)
#define GenerateStructureMasterPntrSize sizeof(GenerateStructureMaster **)
#define AllocPntrArrayGenerateStructureMaster(n) (GenerateStructureMaster **) Calloc(n,GenerateStructureMasterPntrSize)
#define SingCopyGenerateStructureMaster(out,in) memcpy(out,in,GenerateStructureMasterSize)
extern GenerateStructureMaster *CreateGenerateStructureMaster(GenerateStructureMaster *newstruct,
INT id,
CHAR *name,
MoleculeStructureSpecification *BasicSpecification,
FullMoleculeSpecification *FullSpecification);

extern CHAR *GetNameGenerateStructureMaster(GenerateStructureMaster *str);
extern INT  GetIDGenerateStructureMaster(GenerateStructureMaster *str);
extern void PrintGenerateStructureMaster(GenerateStructureMaster *eleptr);
extern void FreeGenerateStructureMaster(GenerateStructureMaster *eleptr);
extern void *AllocGenerateStructureMaster();
extern void WriteBinGenerateStructureMaster(GenerateStructureMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinGenerateStructureMaster(GenerateStructureMaster *eleptr, DbaseLinkedList *file);
extern void xdr_GenerateStructureMaster(XDR *stream, char **eleptr);
extern void CopyFullGenerateStructureMaster(GenerateStructureMaster *newstruct, GenerateStructureMaster *oldstruct);
/*------------------------------------------*/
/*   Structure Generation Structures   */
/* Structure:1201:CurrentStructure

                Completed --(INT) 1 if the structure is completed, 0 otherwise
                Structure --(Graph) The structure as a Graph
              Attachments --(DataSubSet) The list of nodes that are open for attachments
*/
typedef struct currentstructure CurrentStructure;
struct currentstructure {
     INT ID;
     CHAR *Name;
     INT  Completed;
     Graph *Structure;
     DataSubSet *Attachments;
     };
#define CurrentStructureSize sizeof(CurrentStructure)
#define AllocateCurrentStructure (CurrentStructure *) Malloc(CurrentStructureSize)
#define AllocArrayCurrentStructure(n) (CurrentStructure *) Calloc(n,CurrentStructureSize)
#define CurrentStructurePntrSize sizeof(CurrentStructure **)
#define AllocPntrArrayCurrentStructure(n) (CurrentStructure **) Calloc(n,CurrentStructurePntrSize)
#define SingCopyCurrentStructure(out,in) memcpy(out,in,CurrentStructureSize)
extern CurrentStructure *CreateCurrentStructure(CurrentStructure *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  Completed,
                                         Graph *Structure,
                                         DataSubSet *Attachments);

extern CHAR *GetNameCurrentStructure(CurrentStructure *str);
extern INT  GetIDCurrentStructure(CurrentStructure *str);
extern void PrintCurrentStructure(CurrentStructure *eleptr);
extern void FreeCurrentStructure(CurrentStructure *eleptr);
extern void *AllocCurrentStructure();
extern void WriteBinCurrentStructure(CurrentStructure *eleptr, DbaseLinkedList *file);
extern INT ReadBinCurrentStructure(CurrentStructure *eleptr, DbaseLinkedList *file);
extern void xdr_CurrentStructure(XDR *stream, char **eleptr);
extern void CopyFullCurrentStructure(CurrentStructure *newstruct, CurrentStructure *oldstruct);
/*------------------------------------------*/
/*   Structure Generation Structures   */
/* Structure:1202:AttachmentRemoved

                Structure --(Graph) The new graph with no attachment
               Attachment --(INT) The new point of attachment
*/
typedef struct attachmentremoved AttachmentRemoved;
struct attachmentremoved {
     INT ID;
     CHAR *Name;
     Graph *Structure;
     INT  Attachment;
     };
#define AttachmentRemovedSize sizeof(AttachmentRemoved)
#define AllocateAttachmentRemoved (AttachmentRemoved *) Malloc(AttachmentRemovedSize)
#define AllocArrayAttachmentRemoved(n) (AttachmentRemoved *) Calloc(n,AttachmentRemovedSize)
#define AttachmentRemovedPntrSize sizeof(AttachmentRemoved **)
#define AllocPntrArrayAttachmentRemoved(n) (AttachmentRemoved **) Calloc(n,AttachmentRemovedPntrSize)
#define SingCopyAttachmentRemoved(out,in) memcpy(out,in,AttachmentRemovedSize)
extern AttachmentRemoved *CreateAttachmentRemoved(AttachmentRemoved *newstruct,
                                           INT id,
                                           CHAR *name,
                                           Graph *Structure,
                                           INT  Attachment);

extern CHAR *GetNameAttachmentRemoved(AttachmentRemoved *str);
extern INT  GetIDAttachmentRemoved(AttachmentRemoved *str);
extern void PrintAttachmentRemoved(AttachmentRemoved *eleptr);
extern void FreeAttachmentRemoved(AttachmentRemoved *eleptr);
extern void *AllocAttachmentRemoved();
extern void WriteBinAttachmentRemoved(AttachmentRemoved *eleptr, DbaseLinkedList *file);
extern INT ReadBinAttachmentRemoved(AttachmentRemoved *eleptr, DbaseLinkedList *file);
extern void xdr_AttachmentRemoved(XDR *stream, char **eleptr);
extern void CopyFullAttachmentRemoved(AttachmentRemoved *newstruct, AttachmentRemoved *oldstruct);
