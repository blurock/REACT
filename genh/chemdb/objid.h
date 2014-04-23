/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:100:TreeLevelDescription

             IDMultFactor --(INT) The ID Multiplication Factor
                  MaxSize --(INT) The Maximum Size of the id
              LevelIDFunc --(FUNCTION) The routine to get level id
*/
typedef struct treeleveldescription TreeLevelDescription;
struct treeleveldescription {
     INT ID;
     CHAR *Name;
     INT  IDMultFactor;
     INT  MaxSize;
     INT  (*LevelIDFunc)();
     };
#define TreeLevelDescriptionSize sizeof(TreeLevelDescription)
#define AllocateTreeLevelDescription (TreeLevelDescription *) Malloc(TreeLevelDescriptionSize)
#define AllocArrayTreeLevelDescription(n) (TreeLevelDescription *) Calloc(n,TreeLevelDescriptionSize)
#define TreeLevelDescriptionPntrSize sizeof(TreeLevelDescription **)
#define AllocPntrArrayTreeLevelDescription(n) (TreeLevelDescription **) Calloc(n,TreeLevelDescriptionPntrSize)
#define SingCopyTreeLevelDescription(out,in) memcpy(out,in,TreeLevelDescriptionSize)
extern TreeLevelDescription *CreateTreeLevelDescription(TreeLevelDescription *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  IDMultFactor,
                                                 INT  MaxSize);

extern CHAR *GetNameTreeLevelDescription(TreeLevelDescription *str);
extern INT  GetIDTreeLevelDescription(TreeLevelDescription *str);
extern void PrintTreeLevelDescription(TreeLevelDescription *eleptr);
extern void FreeTreeLevelDescription(TreeLevelDescription *eleptr);
extern void *AllocTreeLevelDescription();
extern void WriteBinTreeLevelDescription(TreeLevelDescription *eleptr, DbaseLinkedList *file);
extern INT ReadBinTreeLevelDescription(TreeLevelDescription *eleptr, DbaseLinkedList *file);
extern void xdr_TreeLevelDescription(XDR *stream, char **eleptr);
extern void CopyFullTreeLevelDescription(TreeLevelDescription *newstruct, TreeLevelDescription *oldstruct);
/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:100:ListOfTreeLevelDescriptions

           NumberOfLevels --(INT) The number of tree levels
                   Levels --(TreeLevelDescription) The set of levels
               BindStruct --(INT) The id of the bind structure (to get local list)
                 Database --(INT) The id of the database of structures 
                  KeyType --(INT) The id of the keyword type
*/
typedef struct listoftreeleveldescriptions ListOfTreeLevelDescriptions;
struct listoftreeleveldescriptions {
     INT ID;
     CHAR *Name;
     INT  NumberOfLevels;
     TreeLevelDescription *Levels;
     INT  BindStruct;
     INT  Database;
     INT  KeyType;
     };
#define ListOfTreeLevelDescriptionsSize sizeof(ListOfTreeLevelDescriptions)
#define AllocateListOfTreeLevelDescriptions (ListOfTreeLevelDescriptions *) Malloc(ListOfTreeLevelDescriptionsSize)
#define AllocArrayListOfTreeLevelDescriptions(n) (ListOfTreeLevelDescriptions *) Calloc(n,ListOfTreeLevelDescriptionsSize)
#define ListOfTreeLevelDescriptionsPntrSize sizeof(ListOfTreeLevelDescriptions **)
#define AllocPntrArrayListOfTreeLevelDescriptions(n) (ListOfTreeLevelDescriptions **) Calloc(n,ListOfTreeLevelDescriptionsPntrSize)
#define SingCopyListOfTreeLevelDescriptions(out,in) memcpy(out,in,ListOfTreeLevelDescriptionsSize)
extern ListOfTreeLevelDescriptions *CreateListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *newstruct,
INT id,
CHAR *name,
INT  NumberOfLevels,
TreeLevelDescription *Levels,
INT  BindStruct,
INT  Database,
INT  KeyType);

extern CHAR *GetNameListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *str);
extern INT  GetIDListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *str);
extern void PrintListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr);
extern void FreeListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr);
extern void *AllocListOfTreeLevelDescriptions();
extern void WriteBinListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr, DbaseLinkedList *file);
extern INT ReadBinListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr, DbaseLinkedList *file);
extern void xdr_ListOfTreeLevelDescriptions(XDR *stream, char **eleptr);
extern void CopyFullListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *newstruct, ListOfTreeLevelDescriptions *oldstruct);
/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:101:ObjectIDInfo

        NumberOfObjectIDs --(INT) The number of object id's
                ObjectIDs --(INT) The list of object id's
*/
typedef struct molidinfo ObjectIDInfo;
struct molidinfo {
     INT ID;
     CHAR *Name;
     INT  NumberOfObjectIDs;
     INT *ObjectIDs;
     };
#define ObjectIDInfoSize sizeof(ObjectIDInfo)
#define AllocateObjectIDInfo (ObjectIDInfo *) Malloc(ObjectIDInfoSize)
#define AllocArrayObjectIDInfo(n) (ObjectIDInfo *) Calloc(n,ObjectIDInfoSize)
#define ObjectIDInfoPntrSize sizeof(ObjectIDInfo **)
#define AllocPntrArrayObjectIDInfo(n) (ObjectIDInfo **) Calloc(n,ObjectIDInfoPntrSize)
#define SingCopyObjectIDInfo(out,in) memcpy(out,in,ObjectIDInfoSize)
extern ObjectIDInfo *CreateObjectIDInfo(ObjectIDInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfObjectIDs,
                                 INT *ObjectIDs);

extern CHAR *GetNameObjectIDInfo(ObjectIDInfo *str);
extern INT  GetIDObjectIDInfo(ObjectIDInfo *str);
extern void PrintObjectIDInfo(ObjectIDInfo *eleptr);
extern void FreeObjectIDInfo(ObjectIDInfo *eleptr);
extern void *AllocObjectIDInfo();
extern void WriteBinObjectIDInfo(ObjectIDInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinObjectIDInfo(ObjectIDInfo *eleptr, DbaseLinkedList *file);
extern void xdr_ObjectIDInfo(XDR *stream, char **eleptr);
extern void CopyFullObjectIDInfo(ObjectIDInfo *newstruct, ObjectIDInfo *oldstruct);
/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:100:ObjectIDClass

                     Info --(ObjectIDInfo) The Object Information of this group
             NumberOfKeys --(INT) The number of Keys
                     Keys --(DbaseKeyword) The set of Keys
*/
typedef struct objectidClass ObjectIDClass;
struct objectidClass {
     INT ID;
     CHAR *Name;
     ObjectIDInfo *Info;
     INT  NumberOfKeys;
     DbaseKeyword *Keys;
     };
#define ObjectIDClassSize sizeof(ObjectIDClass)
#define AllocateObjectIDClass (ObjectIDClass *) Malloc(ObjectIDClassSize)
#define AllocArrayObjectIDClass(n) (ObjectIDClass *) Calloc(n,ObjectIDClassSize)
#define ObjectIDClassPntrSize sizeof(ObjectIDClass **)
#define AllocPntrArrayObjectIDClass(n) (ObjectIDClass **) Calloc(n,ObjectIDClassPntrSize)
#define SingCopyObjectIDClass(out,in) memcpy(out,in,ObjectIDClassSize)
extern ObjectIDClass *CreateObjectIDClass(ObjectIDClass *newstruct,
                                   INT id,
                                   CHAR *name,
                                   ObjectIDInfo *Info,
                                   INT  NumberOfKeys,
                                   DbaseKeyword *Keys);

extern CHAR *GetNameObjectIDClass(ObjectIDClass *str);
extern INT  GetIDObjectIDClass(ObjectIDClass *str);
extern void PrintObjectIDClass(ObjectIDClass *eleptr);
extern void FreeObjectIDClass(ObjectIDClass *eleptr);
extern void *AllocObjectIDClass();
extern void WriteBinObjectIDClass(ObjectIDClass *eleptr, DbaseLinkedList *file);
extern INT ReadBinObjectIDClass(ObjectIDClass *eleptr, DbaseLinkedList *file);
extern void xdr_ObjectIDClass(XDR *stream, char **eleptr);
extern void CopyFullObjectIDClass(ObjectIDClass *newstruct, ObjectIDClass *oldstruct);
/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:100:ObjectIDTreeNode

         NumberOfSubTrees --(INT) The number of subtrees
                 SubTrees --(ObjectIDTreeNode) The set of subtrees
                     Info --(ObjectIDClass) The Node Information (if a terminal node)
*/
typedef struct molidtreenode ObjectIDTreeNode;
struct molidtreenode {
     INT ID;
     CHAR *Name;
     INT  NumberOfSubTrees;
     ObjectIDTreeNode *SubTrees;
     ObjectIDClass *Info;
     };
#define ObjectIDTreeNodeSize sizeof(ObjectIDTreeNode)
#define AllocateObjectIDTreeNode (ObjectIDTreeNode *) Malloc(ObjectIDTreeNodeSize)
#define AllocArrayObjectIDTreeNode(n) (ObjectIDTreeNode *) Calloc(n,ObjectIDTreeNodeSize)
#define ObjectIDTreeNodePntrSize sizeof(ObjectIDTreeNode **)
#define AllocPntrArrayObjectIDTreeNode(n) (ObjectIDTreeNode **) Calloc(n,ObjectIDTreeNodePntrSize)
#define SingCopyObjectIDTreeNode(out,in) memcpy(out,in,ObjectIDTreeNodeSize)
extern ObjectIDTreeNode *CreateObjectIDTreeNode(ObjectIDTreeNode *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfSubTrees,
                                         ObjectIDTreeNode *SubTrees,
                                         ObjectIDClass *Info);

extern CHAR *GetNameObjectIDTreeNode(ObjectIDTreeNode *str);
extern INT  GetIDObjectIDTreeNode(ObjectIDTreeNode *str);
extern void PrintObjectIDTreeNode(ObjectIDTreeNode *eleptr);
extern void FreeObjectIDTreeNode(ObjectIDTreeNode *eleptr);
extern void *AllocObjectIDTreeNode();
extern void WriteBinObjectIDTreeNode(ObjectIDTreeNode *eleptr, DbaseLinkedList *file);
extern INT ReadBinObjectIDTreeNode(ObjectIDTreeNode *eleptr, DbaseLinkedList *file);
extern void xdr_ObjectIDTreeNode(XDR *stream, char **eleptr);
extern void CopyFullObjectIDTreeNode(ObjectIDTreeNode *newstruct, ObjectIDTreeNode *oldstruct);
/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:100:ObjectClassification

            TreeOfObjects --(ObjectIDTreeNode) The object tree
              Description --(ListOfTreeLevelDescriptions) The tree descriptions
              Equivalence --(FUNCTION) The equivalence function
         FindElementInSet --(FUNCTION) Find an element in a set of elements
*/
typedef struct objectclassifications ObjectClassification;
struct objectclassifications {
     INT ID;
     CHAR *Name;
     ObjectIDTreeNode *TreeOfObjects;
     ListOfTreeLevelDescriptions *Description;
     INT  (*Equivalence)();
     VOID  (*FindElementInSet)();
     };
#define ObjectClassificationSize sizeof(ObjectClassification)
#define AllocateObjectClassification (ObjectClassification *) Malloc(ObjectClassificationSize)
#define AllocArrayObjectClassification(n) (ObjectClassification *) Calloc(n,ObjectClassificationSize)
#define ObjectClassificationPntrSize sizeof(ObjectClassification **)
#define AllocPntrArrayObjectClassification(n) (ObjectClassification **) Calloc(n,ObjectClassificationPntrSize)
#define SingCopyObjectClassification(out,in) memcpy(out,in,ObjectClassificationSize)
extern ObjectClassification *CreateObjectClassification(ObjectClassification *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 ObjectIDTreeNode *TreeOfObjects,
                                                 ListOfTreeLevelDescriptions *Description,
                                                 INT  (*Equivalence)(),
                                                 VOID  (*FindElementInSet)());

extern CHAR *GetNameObjectClassification(ObjectClassification *str);
extern INT  GetIDObjectClassification(ObjectClassification *str);
extern void PrintObjectClassification(ObjectClassification *eleptr);
extern void FreeObjectClassification(ObjectClassification *eleptr);
extern void *AllocObjectClassification();
extern void WriteBinObjectClassification(ObjectClassification *eleptr, DbaseLinkedList *file);
extern INT ReadBinObjectClassification(ObjectClassification *eleptr, DbaseLinkedList *file);
extern void xdr_ObjectClassification(XDR *stream, char **eleptr);
extern void CopyFullObjectClassification(ObjectClassification *newstruct, ObjectClassification *oldstruct);
/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:100:SetOfObjectClassifications

     NumberOfClassifications --(INT) The number of classifications
          Classifications --(ObjectClassification) The object classifications
*/
typedef struct setofobjectclassifications SetOfObjectClassifications;
struct setofobjectclassifications {
     INT ID;
     CHAR *Name;
     INT  NumberOfClassifications;
     ObjectClassification *Classifications;
     };
#define SetOfObjectClassificationsSize sizeof(SetOfObjectClassifications)
#define AllocateSetOfObjectClassifications (SetOfObjectClassifications *) Malloc(SetOfObjectClassificationsSize)
#define AllocArraySetOfObjectClassifications(n) (SetOfObjectClassifications *) Calloc(n,SetOfObjectClassificationsSize)
#define SetOfObjectClassificationsPntrSize sizeof(SetOfObjectClassifications **)
#define AllocPntrArraySetOfObjectClassifications(n) (SetOfObjectClassifications **) Calloc(n,SetOfObjectClassificationsPntrSize)
#define SingCopySetOfObjectClassifications(out,in) memcpy(out,in,SetOfObjectClassificationsSize)
extern SetOfObjectClassifications *CreateSetOfObjectClassifications(SetOfObjectClassifications *newstruct,
INT id,
CHAR *name,
INT  NumberOfClassifications,
ObjectClassification *Classifications);

extern CHAR *GetNameSetOfObjectClassifications(SetOfObjectClassifications *str);
extern INT  GetIDSetOfObjectClassifications(SetOfObjectClassifications *str);
extern void PrintSetOfObjectClassifications(SetOfObjectClassifications *eleptr);
extern void FreeSetOfObjectClassifications(SetOfObjectClassifications *eleptr);
extern void *AllocSetOfObjectClassifications();
extern void WriteBinSetOfObjectClassifications(SetOfObjectClassifications *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfObjectClassifications(SetOfObjectClassifications *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfObjectClassifications(XDR *stream, char **eleptr);
extern void CopyFullSetOfObjectClassifications(SetOfObjectClassifications *newstruct, SetOfObjectClassifications *oldstruct);
/*------------------------------------------*/
/*   Object Identification Structures   */
/* Structure:100:LocDbaseClassifications

                    Local --(SetOfObjectClassifications) The local classifications
                 Database --(SetOfObjectClassifications) The database classifications
*/
typedef struct localanddatabaseclassifications LocDbaseClassifications;
struct localanddatabaseclassifications {
     INT ID;
     CHAR *Name;
     SetOfObjectClassifications *Local;
     SetOfObjectClassifications *Database;
     };
#define LocDbaseClassificationsSize sizeof(LocDbaseClassifications)
#define AllocateLocDbaseClassifications (LocDbaseClassifications *) Malloc(LocDbaseClassificationsSize)
#define AllocArrayLocDbaseClassifications(n) (LocDbaseClassifications *) Calloc(n,LocDbaseClassificationsSize)
#define LocDbaseClassificationsPntrSize sizeof(LocDbaseClassifications **)
#define AllocPntrArrayLocDbaseClassifications(n) (LocDbaseClassifications **) Calloc(n,LocDbaseClassificationsPntrSize)
#define SingCopyLocDbaseClassifications(out,in) memcpy(out,in,LocDbaseClassificationsSize)
extern LocDbaseClassifications *CreateLocDbaseClassifications(LocDbaseClassifications *newstruct,
INT id,
CHAR *name,
SetOfObjectClassifications *Local,
SetOfObjectClassifications *Database);

extern CHAR *GetNameLocDbaseClassifications(LocDbaseClassifications *str);
extern INT  GetIDLocDbaseClassifications(LocDbaseClassifications *str);
extern void PrintLocDbaseClassifications(LocDbaseClassifications *eleptr);
extern void FreeLocDbaseClassifications(LocDbaseClassifications *eleptr);
extern void *AllocLocDbaseClassifications();
extern void WriteBinLocDbaseClassifications(LocDbaseClassifications *eleptr, DbaseLinkedList *file);
extern INT ReadBinLocDbaseClassifications(LocDbaseClassifications *eleptr, DbaseLinkedList *file);
extern void xdr_LocDbaseClassifications(XDR *stream, char **eleptr);
extern void CopyFullLocDbaseClassifications(LocDbaseClassifications *newstruct, LocDbaseClassifications *oldstruct);
