/*------------------------------------------*/
/*   MolFile Structures   */
/* Structure:10:MolFileAtom

                        X --(FLOAT) The X coordinate
                        Y --(FLOAT) The Y coordinate
                        Z --(FLOAT) The Z coordinate
             AtomicNumber --(INT) The atomic number
                   Charge --(FLOAT) The Charge on the atom 
                  Radical --(INT) If a Free Radical
       NumberOfParameters --(INT) The number of parameters
               Parameters --(INT) The Parameters
*/
typedef struct molfileatom MolFileAtom;
struct molfileatom {
     INT ID;
     CHAR *Name;
     FLOAT  X;
     FLOAT  Y;
     FLOAT  Z;
     INT  AtomicNumber;
     FLOAT  Charge;
     INT  Radical;
     INT  NumberOfParameters;
     INT *Parameters;
     };
#define MolFileAtomSize sizeof(MolFileAtom)
#define AllocateMolFileAtom (MolFileAtom *) Malloc(MolFileAtomSize)
#define AllocArrayMolFileAtom(n) (MolFileAtom *) Calloc(n,MolFileAtomSize)
#define MolFileAtomPntrSize sizeof(MolFileAtom **)
#define AllocPntrArrayMolFileAtom(n) (MolFileAtom **) Calloc(n,MolFileAtomPntrSize)
#define SingCopyMolFileAtom(out,in) memcpy(out,in,MolFileAtomSize)
extern MolFileAtom *CreateMolFileAtom(MolFileAtom *newstruct,
                               INT id,
                               CHAR *name,
                               FLOAT  X,
                               FLOAT  Y,
                               FLOAT  Z,
                               INT  AtomicNumber,
                               FLOAT  Charge,
                               INT  Radical,
                               INT  NumberOfParameters,
                               INT *Parameters);

extern CHAR *GetNameMolFileAtom(MolFileAtom *str);
extern INT  GetIDMolFileAtom(MolFileAtom *str);
extern void PrintMolFileAtom(MolFileAtom *eleptr);
extern void FreeMolFileAtom(MolFileAtom *eleptr);
extern void *AllocMolFileAtom();
extern void WriteBinMolFileAtom(MolFileAtom *eleptr, DbaseLinkedList *file);
extern INT ReadBinMolFileAtom(MolFileAtom *eleptr, DbaseLinkedList *file);
extern void xdr_MolFileAtom(XDR *stream, char **eleptr);
extern void CopyFullMolFileAtom(MolFileAtom *newstruct, MolFileAtom *oldstruct);
/*------------------------------------------*/
/*   MolFile Structures   */
/* Structure:11:MolFileBond

                        I --(INT) The label of the first atom
                        J --(INT) The label of the second atom
                    Order --(INT) The bond order
       NumberOfParameters --(INT) The Number Of Parameters
               Parameters --(INT) The Bond Parameters
*/
typedef struct molfilebond MolFileBond;
struct molfilebond {
     INT ID;
     CHAR *Name;
     INT  I;
     INT  J;
     INT  Order;
     INT  NumberOfParameters;
     INT *Parameters;
     };
#define MolFileBondSize sizeof(MolFileBond)
#define AllocateMolFileBond (MolFileBond *) Malloc(MolFileBondSize)
#define AllocArrayMolFileBond(n) (MolFileBond *) Calloc(n,MolFileBondSize)
#define MolFileBondPntrSize sizeof(MolFileBond **)
#define AllocPntrArrayMolFileBond(n) (MolFileBond **) Calloc(n,MolFileBondPntrSize)
#define SingCopyMolFileBond(out,in) memcpy(out,in,MolFileBondSize)
extern MolFileBond *CreateMolFileBond(MolFileBond *newstruct,
                               INT id,
                               CHAR *name,
                               INT  I,
                               INT  J,
                               INT  Order,
                               INT  NumberOfParameters,
                               INT *Parameters);

extern CHAR *GetNameMolFileBond(MolFileBond *str);
extern INT  GetIDMolFileBond(MolFileBond *str);
extern void PrintMolFileBond(MolFileBond *eleptr);
extern void FreeMolFileBond(MolFileBond *eleptr);
extern void *AllocMolFileBond();
extern void WriteBinMolFileBond(MolFileBond *eleptr, DbaseLinkedList *file);
extern INT ReadBinMolFileBond(MolFileBond *eleptr, DbaseLinkedList *file);
extern void xdr_MolFileBond(XDR *stream, char **eleptr);
extern void CopyFullMolFileBond(MolFileBond *newstruct, MolFileBond *oldstruct);
/*------------------------------------------*/
/*   MolFile Structures   */
/* Structure:12:MolFileMolecule

                   NAtoms --(INT)   The number of atoms in the molecule
                   NBonds --(INT)   The number of bonds in the molecule
                    Atoms --(MolFileAtom)   An array of MolfileAtom structures
                    Bonds --(MolFileBond)   An array of MolfileBonds structures
               Properties --(ASCIIProperties) The set of properties
*/
typedef struct molecularmolfile MolFileMolecule;
struct molecularmolfile {
     INT ID;
     CHAR *Name;
     INT  NAtoms;
     INT  NBonds;
     MolFileAtom *Atoms;
     MolFileBond *Bonds;
     ASCIIProperties *Properties;
     };
#define MolFileMoleculeSize sizeof(MolFileMolecule)
#define AllocateMolFileMolecule (MolFileMolecule *) Malloc(MolFileMoleculeSize)
#define AllocArrayMolFileMolecule(n) (MolFileMolecule *) Calloc(n,MolFileMoleculeSize)
#define MolFileMoleculePntrSize sizeof(MolFileMolecule **)
#define AllocPntrArrayMolFileMolecule(n) (MolFileMolecule **) Calloc(n,MolFileMoleculePntrSize)
#define SingCopyMolFileMolecule(out,in) memcpy(out,in,MolFileMoleculeSize)
extern MolFileMolecule *CreateMolFileMolecule(MolFileMolecule *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NAtoms,
                                       INT  NBonds,
                                       MolFileAtom *Atoms,
                                       MolFileBond *Bonds,
                                       ASCIIProperties *Properties);

extern CHAR *GetNameMolFileMolecule(MolFileMolecule *str);
extern INT  GetIDMolFileMolecule(MolFileMolecule *str);
extern void PrintMolFileMolecule(MolFileMolecule *eleptr);
extern void FreeMolFileMolecule(MolFileMolecule *eleptr);
extern void *AllocMolFileMolecule();
extern void WriteBinMolFileMolecule(MolFileMolecule *eleptr, DbaseLinkedList *file);
extern INT ReadBinMolFileMolecule(MolFileMolecule *eleptr, DbaseLinkedList *file);
extern void xdr_MolFileMolecule(XDR *stream, char **eleptr);
extern void CopyFullMolFileMolecule(MolFileMolecule *newstruct, MolFileMolecule *oldstruct);
/*------------------------------------------*/
/*   MolFile Structures   */
/* Structure:14:MolFileMetaAtom

          NumberOfAliased --(INT) The Number of Possibilities
            AtomicNumbers --(INT) The Atomic Numbers
                  Bonding --(INT) The Bonding 
*/
typedef struct molfilemetaatom MolFileMetaAtom;
struct molfilemetaatom {
     INT ID;
     CHAR *Name;
     INT  NumberOfAliased;
     INT *AtomicNumbers;
     INT *Bonding;
     };
#define MolFileMetaAtomSize sizeof(MolFileMetaAtom)
#define AllocateMolFileMetaAtom (MolFileMetaAtom *) Malloc(MolFileMetaAtomSize)
#define AllocArrayMolFileMetaAtom(n) (MolFileMetaAtom *) Calloc(n,MolFileMetaAtomSize)
#define MolFileMetaAtomPntrSize sizeof(MolFileMetaAtom **)
#define AllocPntrArrayMolFileMetaAtom(n) (MolFileMetaAtom **) Calloc(n,MolFileMetaAtomPntrSize)
#define SingCopyMolFileMetaAtom(out,in) memcpy(out,in,MolFileMetaAtomSize)
extern MolFileMetaAtom *CreateMolFileMetaAtom(MolFileMetaAtom *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfAliased,
                                       INT *AtomicNumbers,
                                       INT *Bonding);

extern CHAR *GetNameMolFileMetaAtom(MolFileMetaAtom *str);
extern INT  GetIDMolFileMetaAtom(MolFileMetaAtom *str);
extern void PrintMolFileMetaAtom(MolFileMetaAtom *eleptr);
extern void FreeMolFileMetaAtom(MolFileMetaAtom *eleptr);
extern void *AllocMolFileMetaAtom();
extern void WriteBinMolFileMetaAtom(MolFileMetaAtom *eleptr, DbaseLinkedList *file);
extern INT ReadBinMolFileMetaAtom(MolFileMetaAtom *eleptr, DbaseLinkedList *file);
extern void xdr_MolFileMetaAtom(XDR *stream, char **eleptr);
extern void CopyFullMolFileMetaAtom(MolFileMetaAtom *newstruct, MolFileMetaAtom *oldstruct);
/*------------------------------------------*/
/*   MolFile Structures   */
/* Structure:15:SetOfMolFileMetaAtoms

        NumberOfMetaAtoms --(INT) The number of MetaAtoms
                MetaAtoms --(MolFileMetaAtom) The Set of MetaAtoms
*/
typedef struct setofmolfilemetaatoms SetOfMolFileMetaAtoms;
struct setofmolfilemetaatoms {
     INT ID;
     CHAR *Name;
     INT  NumberOfMetaAtoms;
     MolFileMetaAtom *MetaAtoms;
     };
#define SetOfMolFileMetaAtomsSize sizeof(SetOfMolFileMetaAtoms)
#define AllocateSetOfMolFileMetaAtoms (SetOfMolFileMetaAtoms *) Malloc(SetOfMolFileMetaAtomsSize)
#define AllocArraySetOfMolFileMetaAtoms(n) (SetOfMolFileMetaAtoms *) Calloc(n,SetOfMolFileMetaAtomsSize)
#define SetOfMolFileMetaAtomsPntrSize sizeof(SetOfMolFileMetaAtoms **)
#define AllocPntrArraySetOfMolFileMetaAtoms(n) (SetOfMolFileMetaAtoms **) Calloc(n,SetOfMolFileMetaAtomsPntrSize)
#define SingCopySetOfMolFileMetaAtoms(out,in) memcpy(out,in,SetOfMolFileMetaAtomsSize)
extern SetOfMolFileMetaAtoms *CreateSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfMetaAtoms,
                                                   MolFileMetaAtom *MetaAtoms);

extern CHAR *GetNameSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *str);
extern INT  GetIDSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *str);
extern void PrintSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr);
extern void FreeSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr);
extern void *AllocSetOfMolFileMetaAtoms();
extern void WriteBinSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfMolFileMetaAtoms(XDR *stream, char **eleptr);
extern void CopyFullSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *newstruct, SetOfMolFileMetaAtoms *oldstruct);
