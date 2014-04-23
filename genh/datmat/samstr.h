/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:10:BaseIntVector

             VectorLength --(INT)  The number of points
                   Vector --(INT)  The vector 
*/
typedef struct basintvec BaseIntVector;
struct basintvec {
     INT ID;
     CHAR *Name;
     INT  VectorLength;
     INT *Vector;
     };
#define BaseIntVectorSize sizeof(BaseIntVector)
#define AllocateBaseIntVector (BaseIntVector *) Malloc(BaseIntVectorSize)
#define AllocArrayBaseIntVector(n) (BaseIntVector *) Calloc(n,BaseIntVectorSize)
#define BaseIntVectorPntrSize sizeof(BaseIntVector **)
#define AllocPntrArrayBaseIntVector(n) (BaseIntVector **) Calloc(n,BaseIntVectorPntrSize)
#define SingCopyBaseIntVector(out,in) memcpy(out,in,BaseIntVectorSize)
extern BaseIntVector *CreateBaseIntVector(BaseIntVector *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  VectorLength,
                                   INT *Vector);

extern CHAR *GetNameBaseIntVector(BaseIntVector *str);
extern INT  GetIDBaseIntVector(BaseIntVector *str);
extern void PrintBaseIntVector(BaseIntVector *eleptr);
extern void FreeBaseIntVector(BaseIntVector *eleptr);
extern void *AllocBaseIntVector();
extern void WriteBinBaseIntVector(BaseIntVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinBaseIntVector(BaseIntVector *eleptr, DbaseLinkedList *file);
extern void xdr_BaseIntVector(XDR *stream, char **eleptr);
extern void CopyFullBaseIntVector(BaseIntVector *newstruct, BaseIntVector *oldstruct);
/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:11:BaseFltVector

             VectorLength --(INT)  The number of points
                   Vector --(FLOAT)  The vector 
*/
typedef struct basfltvec BaseFltVector;
struct basfltvec {
     INT ID;
     CHAR *Name;
     INT  VectorLength;
     FLOAT *Vector;
     };
#define BaseFltVectorSize sizeof(BaseFltVector)
#define AllocateBaseFltVector (BaseFltVector *) Malloc(BaseFltVectorSize)
#define AllocArrayBaseFltVector(n) (BaseFltVector *) Calloc(n,BaseFltVectorSize)
#define BaseFltVectorPntrSize sizeof(BaseFltVector **)
#define AllocPntrArrayBaseFltVector(n) (BaseFltVector **) Calloc(n,BaseFltVectorPntrSize)
#define SingCopyBaseFltVector(out,in) memcpy(out,in,BaseFltVectorSize)
extern BaseFltVector *CreateBaseFltVector(BaseFltVector *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  VectorLength,
                                   FLOAT *Vector);

extern CHAR *GetNameBaseFltVector(BaseFltVector *str);
extern INT  GetIDBaseFltVector(BaseFltVector *str);
extern void PrintBaseFltVector(BaseFltVector *eleptr);
extern void FreeBaseFltVector(BaseFltVector *eleptr);
extern void *AllocBaseFltVector();
extern void WriteBinBaseFltVector(BaseFltVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinBaseFltVector(BaseFltVector *eleptr, DbaseLinkedList *file);
extern void xdr_BaseFltVector(XDR *stream, char **eleptr);
extern void CopyFullBaseFltVector(BaseFltVector *newstruct, BaseFltVector *oldstruct);
/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:12:BaseVector

                     Type --(INT)  The type of Vector
                  Integer --(BaseIntVector)  The Integer Basis Vector (zero if not used)
                    Float --(BaseFltVector)  The Float Basis Vector (zero if not used)
*/
typedef struct basvec BaseVector;
struct basvec {
     INT ID;
     CHAR *Name;
     INT  Type;
     BaseIntVector *Integer;
     BaseFltVector *Float;
     };
#define BaseVectorSize sizeof(BaseVector)
#define AllocateBaseVector (BaseVector *) Malloc(BaseVectorSize)
#define AllocArrayBaseVector(n) (BaseVector *) Calloc(n,BaseVectorSize)
#define BaseVectorPntrSize sizeof(BaseVector **)
#define AllocPntrArrayBaseVector(n) (BaseVector **) Calloc(n,BaseVectorPntrSize)
#define SingCopyBaseVector(out,in) memcpy(out,in,BaseVectorSize)
extern BaseVector *CreateBaseVector(BaseVector *newstruct,
                             INT id,
                             CHAR *name,
                             INT  Type,
                             BaseIntVector *Integer,
                             BaseFltVector *Float);

extern CHAR *GetNameBaseVector(BaseVector *str);
extern INT  GetIDBaseVector(BaseVector *str);
extern void PrintBaseVector(BaseVector *eleptr);
extern void FreeBaseVector(BaseVector *eleptr);
extern void *AllocBaseVector();
extern void WriteBinBaseVector(BaseVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinBaseVector(BaseVector *eleptr, DbaseLinkedList *file);
extern void xdr_BaseVector(XDR *stream, char **eleptr);
extern void CopyFullBaseVector(BaseVector *newstruct, BaseVector *oldstruct);
/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:13:BaseType

                     Type --(INT)  The type of Vector
                  Integer --(INT)  An Integer    
                    Float --(FLOAT)  A Floating Point Number
*/
typedef struct bastyp BaseType;
struct bastyp {
     INT ID;
     CHAR *Name;
     INT  Type;
     INT  Integer;
     FLOAT  Float;
     };
#define BaseTypeSize sizeof(BaseType)
#define AllocateBaseType (BaseType *) Malloc(BaseTypeSize)
#define AllocArrayBaseType(n) (BaseType *) Calloc(n,BaseTypeSize)
#define BaseTypePntrSize sizeof(BaseType **)
#define AllocPntrArrayBaseType(n) (BaseType **) Calloc(n,BaseTypePntrSize)
#define SingCopyBaseType(out,in) memcpy(out,in,BaseTypeSize)
extern BaseType *CreateBaseType(BaseType *newstruct,
                         INT id,
                         CHAR *name,
                         INT  Type,
                         INT  Integer,
                         FLOAT  Float);

extern CHAR *GetNameBaseType(BaseType *str);
extern INT  GetIDBaseType(BaseType *str);
extern void PrintBaseType(BaseType *eleptr);
extern void FreeBaseType(BaseType *eleptr);
extern void *AllocBaseType();
extern void WriteBinBaseType(BaseType *eleptr, DbaseLinkedList *file);
extern INT ReadBinBaseType(BaseType *eleptr, DbaseLinkedList *file);
extern void xdr_BaseType(XDR *stream, char **eleptr);
extern void CopyFullBaseType(BaseType *newstruct, BaseType *oldstruct);
/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:14:SysSamVector

                  Missing --(BaseType)  The Value of a missing value
            NumNotMissing --(INT)  The number of points that are not missing
                     Data --(BaseVector)  The data vector of type Type
*/
typedef struct syssamvec SysSamVector;
struct syssamvec {
     INT ID;
     CHAR *Name;
     BaseType *Missing;
     INT  NumNotMissing;
     BaseVector *Data;
     };
#define SysSamVectorSize sizeof(SysSamVector)
#define AllocateSysSamVector (SysSamVector *) Malloc(SysSamVectorSize)
#define AllocArraySysSamVector(n) (SysSamVector *) Calloc(n,SysSamVectorSize)
#define SysSamVectorPntrSize sizeof(SysSamVector **)
#define AllocPntrArraySysSamVector(n) (SysSamVector **) Calloc(n,SysSamVectorPntrSize)
#define SingCopySysSamVector(out,in) memcpy(out,in,SysSamVectorSize)
extern SysSamVector *CreateSysSamVector(SysSamVector *newstruct,
                                 INT id,
                                 CHAR *name,
                                 BaseType *Missing,
                                 INT  NumNotMissing,
                                 BaseVector *Data);

extern CHAR *GetNameSysSamVector(SysSamVector *str);
extern INT  GetIDSysSamVector(SysSamVector *str);
extern void PrintSysSamVector(SysSamVector *eleptr);
extern void FreeSysSamVector(SysSamVector *eleptr);
extern void *AllocSysSamVector();
extern void WriteBinSysSamVector(SysSamVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysSamVector(SysSamVector *eleptr, DbaseLinkedList *file);
extern void xdr_SysSamVector(XDR *stream, char **eleptr);
extern void CopyFullSysSamVector(SysSamVector *newstruct, SysSamVector *oldstruct);
/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:15:SysSamName

*/
typedef struct syssamname SysSamName;
struct syssamname {
     INT ID;
     CHAR *Name;
     };
#define SysSamNameSize sizeof(SysSamName)
#define AllocateSysSamName (SysSamName *) Malloc(SysSamNameSize)
#define AllocArraySysSamName(n) (SysSamName *) Calloc(n,SysSamNameSize)
#define SysSamNamePntrSize sizeof(SysSamName **)
#define AllocPntrArraySysSamName(n) (SysSamName **) Calloc(n,SysSamNamePntrSize)
#define SingCopySysSamName(out,in) memcpy(out,in,SysSamNameSize)
extern SysSamName *CreateSysSamName(SysSamName *newstruct,
                             INT id,
                             CHAR *name);

extern CHAR *GetNameSysSamName(SysSamName *str);
extern INT  GetIDSysSamName(SysSamName *str);
extern void PrintSysSamName(SysSamName *eleptr);
extern void FreeSysSamName(SysSamName *eleptr);
extern void *AllocSysSamName();
extern void WriteBinSysSamName(SysSamName *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysSamName(SysSamName *eleptr, DbaseLinkedList *file);
extern void xdr_SysSamName(XDR *stream, char **eleptr);
extern void CopyFullSysSamName(SysSamName *newstruct, SysSamName *oldstruct);
/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:16:SysSamNameSet

            NumberOfNames --(INT) The number of Data Points
                    Names --(SysSamName) The set of Names of the Points
*/
typedef struct syssamnameset SysSamNameSet;
struct syssamnameset {
     INT ID;
     CHAR *Name;
     INT  NumberOfNames;
     SysSamName *Names;
     };
#define SysSamNameSetSize sizeof(SysSamNameSet)
#define AllocateSysSamNameSet (SysSamNameSet *) Malloc(SysSamNameSetSize)
#define AllocArraySysSamNameSet(n) (SysSamNameSet *) Calloc(n,SysSamNameSetSize)
#define SysSamNameSetPntrSize sizeof(SysSamNameSet **)
#define AllocPntrArraySysSamNameSet(n) (SysSamNameSet **) Calloc(n,SysSamNameSetPntrSize)
#define SingCopySysSamNameSet(out,in) memcpy(out,in,SysSamNameSetSize)
extern SysSamNameSet *CreateSysSamNameSet(SysSamNameSet *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfNames,
                                   SysSamName *Names);

extern CHAR *GetNameSysSamNameSet(SysSamNameSet *str);
extern INT  GetIDSysSamNameSet(SysSamNameSet *str);
extern void PrintSysSamNameSet(SysSamNameSet *eleptr);
extern void FreeSysSamNameSet(SysSamNameSet *eleptr);
extern void *AllocSysSamNameSet();
extern void WriteBinSysSamNameSet(SysSamNameSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysSamNameSet(SysSamNameSet *eleptr, DbaseLinkedList *file);
extern void xdr_SysSamNameSet(XDR *stream, char **eleptr);
extern void CopyFullSysSamNameSet(SysSamNameSet *newstruct, SysSamNameSet *oldstruct);
/*------------------------------------------*/
/*   Structures For syssamstr.c   */
/* Structure:17:SysSamVectorSet

         NumSystemSamples --(INT) The number of samples
          NumSystemPoints --(INT) The number of Data Points
                     Sets --(SysSamVector) The set of SystemSampleVectors
                  NameSet --(SysSamNameSet)  The set of Names of each data point
*/
typedef struct syssamvecset SysSamVectorSet;
struct syssamvecset {
     INT ID;
     CHAR *Name;
     INT  NumSystemSamples;
     INT  NumSystemPoints;
     SysSamVector *Sets;
     SysSamNameSet *NameSet;
     };
#define SysSamVectorSetSize sizeof(SysSamVectorSet)
#define AllocateSysSamVectorSet (SysSamVectorSet *) Malloc(SysSamVectorSetSize)
#define AllocArraySysSamVectorSet(n) (SysSamVectorSet *) Calloc(n,SysSamVectorSetSize)
#define SysSamVectorSetPntrSize sizeof(SysSamVectorSet **)
#define AllocPntrArraySysSamVectorSet(n) (SysSamVectorSet **) Calloc(n,SysSamVectorSetPntrSize)
#define SingCopySysSamVectorSet(out,in) memcpy(out,in,SysSamVectorSetSize)
extern SysSamVectorSet *CreateSysSamVectorSet(SysSamVectorSet *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumSystemSamples,
                                       INT  NumSystemPoints,
                                       SysSamVector *Sets,
                                       SysSamNameSet *NameSet);

extern CHAR *GetNameSysSamVectorSet(SysSamVectorSet *str);
extern INT  GetIDSysSamVectorSet(SysSamVectorSet *str);
extern void PrintSysSamVectorSet(SysSamVectorSet *eleptr);
extern void FreeSysSamVectorSet(SysSamVectorSet *eleptr);
extern void *AllocSysSamVectorSet();
extern void WriteBinSysSamVectorSet(SysSamVectorSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysSamVectorSet(SysSamVectorSet *eleptr, DbaseLinkedList *file);
extern void xdr_SysSamVectorSet(XDR *stream, char **eleptr);
extern void CopyFullSysSamVectorSet(SysSamVectorSet *newstruct, SysSamVectorSet *oldstruct);
