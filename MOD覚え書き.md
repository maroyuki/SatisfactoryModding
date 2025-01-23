# Satisfactory Modding作成覚え書き
## 他BlueprintInstanceにアクセスする
### RootInstance
GetGameInastanceModuleManeger->FindModule(FString YourModReference)->Cast To RootInstance_YourModReference

### RootGameWorld
GetWorldModuleManeger->FindModule(FString YourModReference)->Cast To RootGameWorld_YourModReference

## VSによるBuild関係

### xxx.generated.hが見つからずにBuildできない
1. StartProjectに対し、commitせずに変更をStashし、pull
2. .\Intermediateや.\Binariesフォルダを削除
4. FactoryGame.uprojectを右クリックし、VSファイルを再生成
5. Build
