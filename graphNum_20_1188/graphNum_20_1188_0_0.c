#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1188_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][16] = {{18446744073709551615LLU,4398046511103LLU,18410715276690587648LLU,18446726481523523583LLU,18411278226644008959LLU,18446744073709551375LLU,18446735380695744512LLU,18446744073709551615LLU,4611686018427386943LLU,18446744073709551104LLU,18446744073709551567LLU,18446744073705357311LLU,18446744073709551599LLU,18446744073709551615LLU,18428729675200069632LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,0LLU,0LLU,18445618173802708992LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU,0LLU,0LLU,17870283321406128128LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,576460752303423487LLU,0LLU,0LLU,0LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446181123756130304LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2251799813685247LLU,18439988674268495871LLU,18446472768992902751LLU,18392685344351322111LLU,18365643133972119551LLU,17401692903917316862LLU,18372672036055776765LLU,44414LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU},{562949953421311LLU,18446739675663040512LLU,72057594037927935LLU,13834987686537969664LLU,18446673661881465850LLU,18446172299707743743LLU,18446744073709551615LLU,18446744073709551615LLU,16140901064495857663LLU,16139767433099870207LLU,10370945447712522231LLU,16125066977143156671LLU,18446744073709518839LLU,255LLU,18446744073709551615LLU,18446744073709551615LLU},{0LLU,0LLU,18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18444492273887477761LLU,18445598245133475839LLU,18442231127897788413LLU,17592186044415LLU,18446603336221196288LLU,18442240474082181119LLU,18441123352811532285LLU,18437696742146047743LLU,18121917550387233783LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18444492273895931903LLU,18446480190918853119LLU,18014398492704767LLU,18446744073709551360LLU},{18446181123764518911LLU,8935141660703064063LLU,18445055210951802783LLU,18446744073709551615LLU,140737488355327LLU,7881299347898368LLU,18446744073709551615LLU,18446532967477018623LLU,18446735243256791039LLU,18446743180356354559LLU,17581912207715729407LLU,18445055223312416767LLU,2251799813685247LLU,18410715276690587392LLU,18445054808310799871LLU,18446744073642443007LLU},{1125899906842623LLU,18446189919849151488LLU,144111064806588159LLU,18446743798831546352LLU,18446744073675997183LLU,18446744073709551615LLU,34359738367LLU,18446735277616529408LLU,18446744073709551615LLU,18014185204226195455LLU,16140311713244250111LLU,18009894907581300723LLU,18446743523953737727LLU,18446744039349813503LLU,6250969885920198641LLU,18446744065186725851LLU},{18446744071578845183LLU,18446739675663041535LLU,18446744073709453311LLU,18014398509213532175LLU,36024398972452863LLU,18446744056529682428LLU,18446744073709551615LLU,8796093022207LLU,17870283321406128128LLU,18446739675663026175LLU,13835058055013720575LLU,18437736874454810623LLU,18378908604309699839LLU,34359738367LLU,18446744073642442751LLU,18446742982787825919LLU},{18446744073709547523LLU,16717361808209084415LLU,18446743953450467327LLU,35081290776575LLU,16140901064495849472LLU,18446744073709453311LLU,18446620928340131583LLU,14987979559889010639LLU,18446743042917394431LLU,68719476735LLU,18374686479671623680LLU,18446744073709551615LLU,18149506489713229823LLU,18230517415523906047LLU,9241382587073557503LLU,18446709834230267903LLU},{18446740775166283775LLU,18446744073709551615LLU,18446744073709541503LLU,18446744073608888319LLU,18446603336221204479LLU,18446744069431361535LLU,18445758911291031551LLU,18446744073678094335LLU,18446744073708740607LLU,18446744073709551615LLU,72057594037927935LLU,0LLU,2303591217989877760LLU,18445970017120915454LLU,9223372036830134271LLU,18445653357772144384LLU},{18446589042568449267LLU,4398046511055LLU,18446744073709551608LLU,18444633011367460861LLU,18445054193056644999LLU,16140848047218229247LLU,18446743661392683008LLU,18446744071830503423LLU,4611686018427387903LLU,18428738468021534718LLU,9223370937880018927LLU,18014398509480960LLU,13834952449820590062LLU,18446744072635809755LLU,7439946584415993856LLU,18429819288396234654LLU},{4544131873105592319LLU,18446743816011449343LLU,13402712489980854279LLU,18446744056546455503LLU,9000443854486765567LLU,18131492099793089487LLU,17879288871376658431LLU,18302910360610402815LLU,18445635765988753215LLU,18446744073709551585LLU,18446744073709551615LLU,18446743803121894399LLU,18446741668527865855LLU,16717361335754358783LLU,18446744004990140415LLU,18176316706365791477LLU},{17365827334841565135LLU,18446744073298575167LLU,16681333020854059007LLU,18412949501498096955LLU,17555031347490193407LLU,13726969740079910719LLU,576454120890695679LLU,144115173043470334LLU,18446744073650830576LLU,18014398308154911LLU,18446744073709551582LLU,18446744073709551615LLU,18446744073707978751LLU,18444484025410387959LLU,18212556961805762559LLU,14123281781733585919LLU},{4503052014813055LLU,18446744073709551612LLU,124974812340813759LLU,576451885880311807LLU,18446612132307927038LLU,17302829768349057027LLU,1125899906056191LLU,18446744073709289472LLU,18446744073709551615LLU,18446743523949559547LLU,17870283321368387583LLU,18445618173802250239LLU,16211269671117063167LLU,18446744073642475519LLU,18436608498096406527LLU,11475158656329220095LLU},{18446181673511944191LLU,18378662311603731459LLU,18446635222058401791LLU,18446742699319130352LLU,18446744060791095295LLU,1151795604708392959LLU,18446744072098938819LLU,18446524171384258559LLU,18446735238961856511LLU,18446744004994269183LLU,18446744073709551615LLU,18446620928306577407LLU,2305833663364857855LLU,18392982318865186560LLU,18446585744035151667LLU,8643216916963393535LLU},{1152912225598439423LLU,72053198138900428LLU,2305843009212809208LLU,8935141659345143805LLU,1151232654746583038LLU,15132094593337671676LLU,18446743661391896639LLU,18446744071830241281LLU,17870283325701095423LLU,18446744073705607166LLU,18446744073705875455LLU,18446744073709551615LLU,16366081045788884991LLU,18014397369679871LLU,18446744073373942015LLU,13785507601691676671LLU},{18392208288348369151LLU,18392278664105377023LLU,18158513696485146623LLU,18446744058676575191LLU,18298125286006317057LLU,9204233937461704671LLU,17942234262800433103LLU,18320493767741669375LLU,18446744069481688959LLU,18446744005258510311LLU,18374686479675817983LLU,18446744073709551615LLU,18446744065253834751LLU,18433197785512538895LLU,9799832720975593335LLU,9004929856265190911LLU}};

static uint_fast64_t D[20][16] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1873391891869859839LLU,11493076233227311608LLU,18445886421296774397LLU,18437754466640855039LLU,18446462735905226255LLU,18383676941967525887LLU,18446735293974366207LLU,9294338914821136895LLU,18428747263124701183LLU,13910183825532394751LLU,13427781295058911596LLU,18446744073709551615LLU,18446744073709551615LLU},{6150791191081254910LLU,13068520762209035605LLU,18444133538729489646LLU,18446744073709551615LLU,18446744073709551615LLU,18444492273895866367LLU,7906069097288708694LLU,7743356503942683483LLU,17777780986027114477LLU,17644709577435906047LLU,11347298074439281404LLU,17640273865858578921LLU,18446744073709530492LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18445716028173320195LLU,7779963958236020735LLU,18345958185891633947LLU,13210521452624592895LLU,18446522683837723474LLU,18446083771506294267LLU,18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,11507812187239726080LLU,7191825086118879111LLU,11507186277455155007LLU,18446744073709517767LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{12296980928164528125LLU,16045003426974046890LLU,139425219816943605LLU,18446722887418265600LLU,6954120774613467135LLU,4500971097391886LLU,13173011435152330153LLU,13663388536328023293LLU,18120765257830856759LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,15816633163951636479LLU,15486753140236072950LLU,1003950305944927258LLU,14697919596388679168LLU,18439970970413301699LLU,14699747508683270039LLU,18446744073709551587LLU,5018962778650640127LLU,18444007843650513441LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17197839602044370943LLU,18410976270556524207LLU,948809144205063LLU,18446744039349813248LLU,18446744073709551615LLU,18446744073709551615LLU,9101722059452414975LLU,18392693453256343166LLU,9115272245492137212LLU,4536560248177157950LLU,18446744073709551507LLU,18431465905259107806LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18410715276690587647LLU,5236243807376244735LLU,11492844688967912621LLU,18445155204629102325LLU,15814407614978064383LLU,15486743107148396454LLU,17135842968056989658LLU,7740966382743471103LLU,18354364986860942715LLU,7746028004105369302LLU,18446744073709541051LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{6151917090988097535LLU,4133952024384206165LLU,18444701166057488271LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,5278218757873318743LLU,8248905549906154482LLU,569599739163377662LLU,18446744004990074880LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15503357142259269631LLU,18444614934067727411LLU,18446744073642443007LLU},{18443366373989023743LLU,17868564569951817727LLU,18439974637812040956LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18445618181910062844LLU,14972216961193213951LLU,17941354928391815169LLU,13976985215218745343LLU,11520744274941444033LLU,13965660488088937347LLU,18446744073709551585LLU,7926057030291259647LLU,15718042676739053LLU,18446744073709551360LLU},{18446744071566890391LLU,7779968356282531839LLU,18437156293119458267LLU,17877596679568228351LLU,132212244735903LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,9223372036854775807LLU,4595923144853668140LLU,18095321603196837950LLU,4611107434256079999LLU,18376438993279253534LLU,18446744073709551615LLU,18441605882895488479LLU,18446742982787825919LLU},{18446278978138696299LLU,18446185521802641407LLU,18427599437250289215LLU,16710174922898292735LLU,18446717479206944359LLU,18446478437565595395LLU,18446744073709551615LLU,18446744073709551615LLU,13835058055282163711LLU,17888024474918272723LLU,8646877183014281167LLU,17887171819874615280LLU,4539029309451789295LLU,18446744073709551507LLU,6240829908216709104LLU,18446744065186725851LLU},{3733479790066270207LLU,2292225780939748336LLU,3312429411768203271LLU,18446740500174818926LLU,8553461592283414527LLU,16348066643066739566LLU,4548630392910846451LLU,4609645324812911102LLU,18438730832965303742LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,15563593619024052222LLU,18444615419189841851LLU,18445653357764482815LLU},{14717666730365157375LLU,16158493233494113295LLU,15276209799658897407LLU,18446743949957067153LLU,14541560246825910271LLU,2107681997089286047LLU,13907112213224881679LLU,13852931579132772289LLU,18446742977964408447LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18149506498303098879LLU,18169770764961185791LLU,18446739740288872567LLU,18446709834170821119LLU},{17298326104053776383LLU,18446744073701164031LLU,16285016252571713535LLU,11385099857992613647LLU,17329741413952256511LLU,18310791656737063167LLU,774056185954303LLU,1099486461950LLU,18446744073709551600LLU,18446744022169745407LLU,18445653358174337535LLU,18446743798965862399LLU,18296714610402598143LLU,18446735294526936958LLU,18446744073709551615LLU,15690395906093904119LLU},{18446678103010312131LLU,18446744073306898191LLU,18446744073709551615LLU,18410750461062675961LLU,16140899969245642751LLU,11529212851333791741LLU,18446163531570085887LLU,18446744056563007439LLU,18383693438342117375LLU,68452081663LLU,18446744073709551614LLU,17592085381119LLU,16960423705524109310LLU,13723435631036579313LLU,18176528096067321855LLU,16707225417467035551LLU},{4611544043451518207LLU,18446743816011513855LLU,13835058055282163711LLU,8935141660703059967LLU,4611686018419007360LLU,18158447726607597567LLU,18446568151849107455LLU,18446743111630581823LLU,18445619269555441663LLU,18446744069682229247LLU,72056494526818303LLU,18446744073709027328LLU,10934739627952570367LLU,16419455729586400207LLU,7493989779944505343LLU,18331796452934672380LLU},{18446744073708230103LLU,18375249427485949951LLU,18446607733328181759LLU,18418031968159660287LLU,18446743232969303967LLU,18446744073709551615LLU,18446744071683669952LLU,18446744073709551615LLU,9223372032559808527LLU,558723430724140975LLU,13764125278550884350LLU,567313090438233103LLU,18446660471632953342LLU,18428738471293091839LLU,12501746223429975823LLU,8643216856762548142LLU},{18446744073703079743LLU,16717358303509467135LLU,18412966956244142072LLU,36015497776463871LLU,18446604434919653374LLU,18446744073709551615LLU,18446744047871649535LLU,14972216961193213951LLU,17941354928391847921LLU,18446744073709551224LLU,18446744073705357313LLU,18446743803121894399LLU,18444630606070349825LLU,7926329709174980607LLU,18142747250042811391LLU,11475157634198273909LLU},{18446425215337034703LLU,18446744073709551615LLU,18446603472603175039LLU,18412965001934405631LLU,18446744056538062975LLU,18445686889252913151LLU,18446392227962781695LLU,18446736377102991359LLU,18446744073709551615LLU,18014333883645831LLU,18374687579183251422LLU,18446603336221720575LLU,9223354712028872703LLU,18446744056261236534LLU,11312765122575335423LLU,8214143502221574115LLU},{17582052634800947199LLU,2305838886037225468LLU,8034562472717320184LLU,18446728680534171519LLU,17851002302681317375LLU,17798225727360851836LLU,4611118363337286143LLU,4611686018427129854LLU,17871409221312953840LLU,18446744073706397310LLU,18446744073709551615LLU,140737488355327LLU,17255559564456034304LLU,2305695674604699647LLU,18429011150176718847LLU,10366722808135530271LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][16] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1873391891869859839LLU,11493076233227311608LLU,18445886421296774397LLU,18437754466640855039LLU,18446462735905226255LLU,18383676941967525887LLU,18446735293974366207LLU,9294338914821136895LLU,18428747263124701183LLU,13910183825532394751LLU,13427781295058911596LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[20];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    cnt[4] = 0;
    cnt[5] = 0;
    cnt[6] = 0;
    cnt[7] = 0;
    cnt[8] = 0;
    cnt[9] = 0;
    cnt[10] = 0;
    cnt[11] = 0;
    cnt[12] = 0;
    cnt[13] = 0;
    cnt[14] = 0;
    cnt[15] = 0;
    cnt[16] = 0;
    cnt[17] = 0;
    cnt[18] = 0;
    cnt[19] = 0;

    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
            : "r" (buf[0]), "r" (buf[1]), "r" (buf[2]), "r" (buf[3]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[4]), "+r" (cnt[5]), "+r" (cnt[6]), "+r" (cnt[7])
            : "r" (buf[4]), "r" (buf[5]), "r" (buf[6]), "r" (buf[7]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[8]), "+r" (cnt[9]), "+r" (cnt[10]), "+r" (cnt[11])
            : "r" (buf[8]), "r" (buf[9]), "r" (buf[10]), "r" (buf[11]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13]), "+r" (cnt[14]), "+r" (cnt[15])
            : "r" (buf[12]), "r" (buf[13]), "r" (buf[14]), "r" (buf[15]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17]), "+r" (cnt[18]), "+r" (cnt[19])
            : "r" (buf[16]), "r" (buf[17]), "r" (buf[18]), "r" (buf[19]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19];
}

#elif UINTPTR_MAX == 0xffffffff // 32-bit
int counter (unsigned long long i)
{
  unsigned int i1 = i, i2 = i >> 32;
  i1 = i1 - ((i1 >> 1) & 0x55555555);
  i2 = i2 - ((i2 >> 1) & 0x55555555);
  i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
  i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
  i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
  i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
  return ((i1 + i2) * 0x1010101) >> 24;
}

#else
#error "this cpu doesn't seem to be 32-bit or 64-bit. I don't know how to deal with this."
#endif
void f(uint_fast8_t i, uint_fast8_t y0){
    if(y0){
        A[i][0] = A[i-1][0] & C[i][0];
        A[i][1] = A[i-1][1] & C[i][1];
        A[i][2] = A[i-1][2] & C[i][2];
        A[i][3] = A[i-1][3] & C[i][3];
        A[i][4] = A[i-1][4] & C[i][4];
        A[i][5] = A[i-1][5] & C[i][5];
        A[i][6] = A[i-1][6] & C[i][6];
        A[i][7] = A[i-1][7] & C[i][7];
        A[i][8] = A[i-1][8] & C[i][8];
        A[i][9] = A[i-1][9] & C[i][9];
        A[i][10] = A[i-1][10] & C[i][10];
        A[i][11] = A[i-1][11] & C[i][11];
        A[i][12] = A[i-1][12] & C[i][12];
        A[i][13] = A[i-1][13] & C[i][13];
        A[i][14] = A[i-1][14] & C[i][14];
        A[i][15] = A[i-1][15] & C[i][15];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];
        A[i][8] = A[i-1][8] & D[i][8];
        A[i][9] = A[i-1][9] & D[i][9];
        A[i][10] = A[i-1][10] & D[i][10];
        A[i][11] = A[i-1][11] & D[i][11];
        A[i][12] = A[i-1][12] & D[i][12];
        A[i][13] = A[i-1][13] & D[i][13];
        A[i][14] = A[i-1][14] & D[i][14];
        A[i][15] = A[i-1][15] & D[i][15];

    }
}

void printout(){
    sprintf(str, "[                    ,%5d]\n", this);
    str[1] = X[0] ^ 48;
    str[2] = X[1] ^ 48;
    str[3] = X[2] ^ 48;
    str[4] = X[3] ^ 48;
    str[5] = X[4] ^ 48;
    str[6] = X[5] ^ 48;
    str[7] = X[6] ^ 48;
    str[8] = X[7] ^ 48;
    str[9] = X[8] ^ 48;
    str[10] = X[9] ^ 48;
    str[11] = X[10] ^ 48;
    str[12] = X[11] ^ 48;
    str[13] = X[12] ^ 48;
    str[14] = X[13] ^ 48;
    str[15] = X[14] ^ 48;
    str[16] = X[15] ^ 48;
    str[17] = X[16] ^ 48;
    str[18] = X[17] ^ 48;
    str[19] = X[18] ^ 48;
    str[20] = X[19] ^ 48;

}


void checkifbest(){
    uint_fast64_t * thisbuf = A[maxpos];
    this = counter(thisbuf);

    if(this == best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
    }

    if(this > best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

}

int r(){
    goto startnocarry;
    
    startnocarry:
        if(i == maxpos){
            if(X[i]){
                X[i] = 0;
                i--;
                goto startcarry;
            }else{
                f(i, 0);
                checkifbest();
                X[i] = 1;
                f(i, 1);
                checkifbest();
                X[i] = 0;
                i--;
                goto startcarry;
            }
        }else{
            f(i, X[i]);
            i++;
            goto startnocarry;
        }
        
    startcarry:
        if(X[i] && (i != endhere)){
            X[i] = 0;
            i--;
            goto startcarry;
        }else{
            if(i == endhere){
                goto end;
            }else{
                X[i] = 1;
                f(i, 1);
                i++;
                goto startnocarry;
            }
        }

    end:
        return 0;
}
int main(){
fout = fopener;
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,4],[2,6],[3,6],[3,7],[4,8],[4,9],[5,7],[5,8],[5,9],[6,7],[6,8],[7,9],[8,9]]\n", fout);
    if(endhere){
        uint_fast8_t bitpos = 0;
        uint_fast8_t thisbit;
        while(starthere){
            thisbit = starthere & 1;
            X[bitpos] = thisbit;
            f(bitpos, thisbit);
            bitpos++;
            starthere >>= 1;
        }
        i = endhere;
        r();
    }else{
        i = 0;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}
