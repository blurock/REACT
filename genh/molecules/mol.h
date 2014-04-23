/*------------------------------------------*/
/*   Molecule Structures   */
/* Structure:0:AtomicNumberCount

                   ACount --(INT) The number of this atomic number
         NumberOfValences --(INT) The number of different valences
                 Valences --(INT) The Set of Valences
                  VCounts --(INT) The number of each valence
*/
typedef struct atomicnumbercount AtomicNumberCount;
struct atomicnumbercount {
     INT ID;
     CHAR *Name;
     INT  ACount;
     INT  NumberOfValences;
     INT *Valences;
     INT *VCounts;
     };
#define AtomicNumberCountSize sizeof(AtomicNumberCount)
#define AllocateAtomicNumberCount (AtomicNumberCount *) Malloc(AtomicNumberCountSize)
#define AllocArrayAtomicNumberCount(n) (AtomicNumberCount *) Calloc(n,AtomicNumberCountSize)
#define AtomicNumberCountPntrSize sizeof(AtomicNumberCount **)
#define AllocPntrArrayAtomicNumberCount(n) (AtomicNumberCount **) Calloc(n,AtomicNumberCountPntrSize)
#define SingCopyAtomicNumberCount(out,in) memcpy(out,in,AtomicNumberCountSize)
extern AtomicNumberCount *CreateAtomicNumberCount(AtomicNumberCount *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  ACount,
                                           INT  NumberOfValences,
                                           INT *Valences,
                                           INT *VCounts);

extern CHAR *GetNameAtomicNumberCount(AtomicNumberCount *str);
extern INT  GetIDAtomicNumberCount(AtomicNumberCount *str);
extern void PrintAtomicNumberCount(AtomicNumberCount *eleptr);
extern void FreeAtomicNumberCount(AtomicNumberCount *eleptr);
extern void *AllocAtomicNumberCount();
extern void WriteBinAtomicNumberCount(AtomicNumberCount *eleptr, DbaseLinkedList *file);
extern INT ReadBinAtomicNumberCount(AtomicNumberCount *eleptr, DbaseLinkedList *file);
extern void xdr_AtomicNumberCount(XDR *stream, char **eleptr);
extern void CopyFullAtomicNumberCount(AtomicNumberCount *newstruct, AtomicNumberCount *oldstruct);
/*------------------------------------------*/
/*   Molecule Structures   */
/* Structure:0:MoleculeAtomCounts

       NumberOfAtomCounts --(INT) The number of Difference Atoms
               AtomCounts --(AtomicNumberCount) The total counts of atoms and valence
            NumberOfAtoms --(INT) The number of atoms in the molecule
                 Valences --(INT) The set of Valences
*/
typedef struct moleculeatomcounts MoleculeAtomCounts;
struct moleculeatomcounts {
     INT ID;
     CHAR *Name;
     INT  NumberOfAtomCounts;
     AtomicNumberCount *AtomCounts;
     INT  NumberOfAtoms;
     INT *Valences;
     };
#define MoleculeAtomCountsSize sizeof(MoleculeAtomCounts)
#define AllocateMoleculeAtomCounts (MoleculeAtomCounts *) Malloc(MoleculeAtomCountsSize)
#define AllocArrayMoleculeAtomCounts(n) (MoleculeAtomCounts *) Calloc(n,MoleculeAtomCountsSize)
#define MoleculeAtomCountsPntrSize sizeof(MoleculeAtomCounts **)
#define AllocPntrArrayMoleculeAtomCounts(n) (MoleculeAtomCounts **) Calloc(n,MoleculeAtomCountsPntrSize)
#define SingCopyMoleculeAtomCounts(out,in) memcpy(out,in,MoleculeAtomCountsSize)
extern MoleculeAtomCounts *CreateMoleculeAtomCounts(MoleculeAtomCounts *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfAtomCounts,
                                             AtomicNumberCount *AtomCounts,
                                             INT  NumberOfAtoms,
                                             INT *Valences);

extern CHAR *GetNameMoleculeAtomCounts(MoleculeAtomCounts *str);
extern INT  GetIDMoleculeAtomCounts(MoleculeAtomCounts *str);
extern void PrintMoleculeAtomCounts(MoleculeAtomCounts *eleptr);
extern void FreeMoleculeAtomCounts(MoleculeAtomCounts *eleptr);
extern void *AllocMoleculeAtomCounts();
extern void WriteBinMoleculeAtomCounts(MoleculeAtomCounts *eleptr, DbaseLinkedList *file);
extern INT ReadBinMoleculeAtomCounts(MoleculeAtomCounts *eleptr, DbaseLinkedList *file);
extern void xdr_MoleculeAtomCounts(XDR *stream, char **eleptr);
extern void CopyFullMoleculeAtomCounts(MoleculeAtomCounts *newstruct, MoleculeAtomCounts *oldstruct);
/*------------------------------------------*/
/*   Molecule Structures   */
/* Structure:81:MoleculeSubGraph

                 SubGraph --(Graph) The SubGraph
            WithHydrogens --(DataSubSet) The Atomset with all the hydrogens
               HeavyAtoms --(DataSubSet) The Atomset with only Heavy Atoms
                 Symmetry --(SetOfPairSets) The subgraph matchings with itself (representing symmetry)
*/
typedef struct moleculesubgraph MoleculeSubGraph;
struct moleculesubgraph {
     INT ID;
     CHAR *Name;
     Graph *SubGraph;
     DataSubSet *WithHydrogens;
     DataSubSet *HeavyAtoms;
     SetOfPairSets *Symmetry;
     };
#define MoleculeSubGraphSize sizeof(MoleculeSubGraph)
#define AllocateMoleculeSubGraph (MoleculeSubGraph *) Malloc(MoleculeSubGraphSize)
#define AllocArrayMoleculeSubGraph(n) (MoleculeSubGraph *) Calloc(n,MoleculeSubGraphSize)
#define MoleculeSubGraphPntrSize sizeof(MoleculeSubGraph **)
#define AllocPntrArrayMoleculeSubGraph(n) (MoleculeSubGraph **) Calloc(n,MoleculeSubGraphPntrSize)
#define SingCopyMoleculeSubGraph(out,in) memcpy(out,in,MoleculeSubGraphSize)
extern MoleculeSubGraph *CreateMoleculeSubGraph(MoleculeSubGraph *newstruct,
                                         INT id,
                                         CHAR *name,
                                         Graph *SubGraph,
                                         DataSubSet *WithHydrogens,
                                         DataSubSet *HeavyAtoms,
                                         SetOfPairSets *Symmetry);

extern CHAR *GetNameMoleculeSubGraph(MoleculeSubGraph *str);
extern INT  GetIDMoleculeSubGraph(MoleculeSubGraph *str);
extern void PrintMoleculeSubGraph(MoleculeSubGraph *eleptr);
extern void FreeMoleculeSubGraph(MoleculeSubGraph *eleptr);
extern void *AllocMoleculeSubGraph();
extern void WriteBinMoleculeSubGraph(MoleculeSubGraph *eleptr, DbaseLinkedList *file);
extern INT ReadBinMoleculeSubGraph(MoleculeSubGraph *eleptr, DbaseLinkedList *file);
extern void xdr_MoleculeSubGraph(XDR *stream, char **eleptr);
extern void CopyFullMoleculeSubGraph(MoleculeSubGraph *newstruct, MoleculeSubGraph *oldstruct);
/*------------------------------------------*/
/*   Molecule Structures   */
/* Structure:80:MoleculeInfo

                  Molfile --(MolFileMolecule) The Molecule Molfile
               Electronic --(MoleculeElectronic) The Electronic Molecular Info
               Properties --(SetOfPropertyValues) The set of extra property values for the molecule
*/
typedef struct moleculeinfo MoleculeInfo;
struct moleculeinfo {
     INT ID;
     CHAR *Name;
     MolFileMolecule *Molfile;
     MoleculeElectronic *Electronic;
     SetOfPropertyValues *Properties;
     };
#define MoleculeInfoSize sizeof(MoleculeInfo)
#define AllocateMoleculeInfo (MoleculeInfo *) Malloc(MoleculeInfoSize)
#define AllocArrayMoleculeInfo(n) (MoleculeInfo *) Calloc(n,MoleculeInfoSize)
#define MoleculeInfoPntrSize sizeof(MoleculeInfo **)
#define AllocPntrArrayMoleculeInfo(n) (MoleculeInfo **) Calloc(n,MoleculeInfoPntrSize)
#define SingCopyMoleculeInfo(out,in) memcpy(out,in,MoleculeInfoSize)
extern MoleculeInfo *CreateMoleculeInfo(MoleculeInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 MolFileMolecule *Molfile,
                                 MoleculeElectronic *Electronic,
                                 SetOfPropertyValues *Properties);

extern CHAR *GetNameMoleculeInfo(MoleculeInfo *str);
extern INT  GetIDMoleculeInfo(MoleculeInfo *str);
extern void PrintMoleculeInfo(MoleculeInfo *eleptr);
extern void FreeMoleculeInfo(MoleculeInfo *eleptr);
extern void *AllocMoleculeInfo();
extern void WriteBinMoleculeInfo(MoleculeInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinMoleculeInfo(MoleculeInfo *eleptr, DbaseLinkedList *file);
extern void xdr_MoleculeInfo(XDR *stream, char **eleptr);
extern void CopyFullMoleculeInfo(MoleculeInfo *newstruct, MoleculeInfo *oldstruct);
/*------------------------------------------*/
/*   Molecule Structures   */
/* Structure:81:MoleculeSet

        NumberOfMolecules --(INT) The number of molecules in the set
                Molecules --(MoleculeInfo) The set of molecules
            PropertyTypes --(SetOfPropertyTypes) The property types for a set of molecules
                MetaAtoms --(SetOfMolFileMetaAtoms) Meta Atom Information
*/
typedef struct moleculeset MoleculeSet;
struct moleculeset {
     INT ID;
     CHAR *Name;
     INT  NumberOfMolecules;
     MoleculeInfo *Molecules;
     SetOfPropertyTypes *PropertyTypes;
     SetOfMolFileMetaAtoms *MetaAtoms;
     };
#define MoleculeSetSize sizeof(MoleculeSet)
#define AllocateMoleculeSet (MoleculeSet *) Malloc(MoleculeSetSize)
#define AllocArrayMoleculeSet(n) (MoleculeSet *) Calloc(n,MoleculeSetSize)
#define MoleculeSetPntrSize sizeof(MoleculeSet **)
#define AllocPntrArrayMoleculeSet(n) (MoleculeSet **) Calloc(n,MoleculeSetPntrSize)
#define SingCopyMoleculeSet(out,in) memcpy(out,in,MoleculeSetSize)
extern MoleculeSet *CreateMoleculeSet(MoleculeSet *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfMolecules,
                               MoleculeInfo *Molecules,
                               SetOfPropertyTypes *PropertyTypes,
                               SetOfMolFileMetaAtoms *MetaAtoms);

extern CHAR *GetNameMoleculeSet(MoleculeSet *str);
extern INT  GetIDMoleculeSet(MoleculeSet *str);
extern void PrintMoleculeSet(MoleculeSet *eleptr);
extern void FreeMoleculeSet(MoleculeSet *eleptr);
extern void *AllocMoleculeSet();
extern void WriteBinMoleculeSet(MoleculeSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinMoleculeSet(MoleculeSet *eleptr, DbaseLinkedList *file);
extern void xdr_MoleculeSet(XDR *stream, char **eleptr);
extern void CopyFullMoleculeSet(MoleculeSet *newstruct, MoleculeSet *oldstruct);
