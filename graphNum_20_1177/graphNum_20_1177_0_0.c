#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1177_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][15] = {{17870388874522525695LLU,18430981475013754879LLU,18446744004986929151LLU,576460752303423487LLU,0LLU,18446744073692777472LLU,18446743949155500063LLU,18379190079286410239LLU,18446744073709551615LLU,18446744073709551615LLU,18446744004990074879LLU,8589934591LLU,18446744073709486081LLU,1125899906842623LLU,281474976710652LLU},{18446744073709551615LLU,18446744073709551615LLU,137438953471LLU,0LLU,0LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU,0LLU,18446181123756130304LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,562949953421311LLU,0LLU,0LLU,0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446708889337462784LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073692776447LLU,13763000332395216895LLU,18375529650456099247LLU,18445618138369228798LLU,11378199110277195579LLU,17581207691189938175LLU,847870LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{35184372088831LLU,18446744073642442752LLU,18428729950077976575LLU,16140901064495857663LLU,13546607737612137855LLU,18446744073709551357LLU,18446744073709551615LLU,13907115649320091647LLU,18410678992772234207LLU,9196349588686216447LLU,14966566570132742134LLU,18446744073708765151LLU,18446726481523507200LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,67108863LLU,18014261070528512LLU,18446744069414780928LLU,18374684280514150399LLU,27021597781000127LLU,18446744073709551584LLU,18446708887189913597LLU,17942340915444056063LLU,18446744073709551615LLU,18446744065119616975LLU,18446744073709551551LLU,17592186044415LLU,18446744056529682432LLU,281474976710655LLU},{18446744073709420545LLU,15780524858229653503LLU,18446744068256953182LLU,17870283321406193663LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18444492273895866367LLU,576243048793302847LLU,13830554313920737151LLU,17761527877389511743LLU,18446744065120533631LLU,6881465046250029055LLU,18445618188130276703LLU,281474976710655LLU},{0LLU,0LLU,18446743936270598144LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{576460752303292419LLU,18446744073642442752LLU,18428730224955881471LLU,17870283325701095423LLU,18446603336221196287LLU,18446744073709551615LLU,4294967295LLU,14122725481480454144LLU,2305843009213693951LLU,18446744073709551615LLU,18446744073709550847LLU,18446744065121713663LLU,18446726481523572735LLU,18445618190982578175LLU,281474976710655LLU},{18446739675560542207LLU,18446744073709551487LLU,18446744073709551615LLU,769829113501319167LLU,11529215046035439600LLU,18446744073709551600LLU,17906312117753999295LLU,138856291893223LLU,18437736874454810624LLU,18446744073709551615LLU,18446744073709551615LLU,14411395525226004479LLU,18446733344587620285LLU,18222688892736241663LLU,281474976677890LLU},{17293822569102704639LLU,18338657545339395831LLU,17906312116789313487LLU,18446742974197923839LLU,18446744073709551615LLU,18445547254195421183LLU,9798143114664214527LLU,18446737476539109375LLU,9007199254740991LLU,0LLU,18446744073709551614LLU,18446744073701163007LLU,18428745031752744959LLU,18446416126331047887LLU,281474909634559LLU},{11529215011694051327LLU,18446181261194821631LLU,14411518807585562623LLU,18446744073709551487LLU,18445055223849025551LLU,18446744073239789567LLU,18446727581035133055LLU,18446744073306898431LLU,18446744073709551615LLU,18446744073709551615LLU,1LLU,18410697821942448128LLU,18014329789218755LLU,16077780197888491516LLU,281406324342783LLU},{18428725068809633791LLU,562949953421311LLU,4611686018427387392LLU,4611686018360803264LLU,18430981062690590719LLU,9295425233382539251LLU,18446744073701163007LLU,4611686018427387903LLU,18374686479663235072LLU,18446709988816584703LLU,4611686018426372079LLU,16066554270069030840LLU,18446744073709551615LLU,13167399410524422147LLU,280993938275842LLU},{9223372036786093959LLU,18446744073709551424LLU,18446727443596182015LLU,18446743811783589951LLU,18446744073684385776LLU,9214369235646545919LLU,17996401703158546400LLU,18446744073709551615LLU,18005391310235631615LLU,18446744073709551615LLU,18446607725677772767LLU,18446673601886158847LLU,18446744073685434367LLU,18295871407428534271LLU,277625612239359LLU},{18438018332268412911LLU,18442240466027020285LLU,18336403683813392379LLU,18419722441442983159LLU,18446708889337724927LLU,17293804839477452799LLU,18446603301859362814LLU,18433233034300882943LLU,18446744065388052479LLU,18446744039349813248LLU,18446744073709551615LLU,18428747266312372223LLU,18445687992791070783LLU,16212958658530639871LLU,267731080346559LLU},{17879255353468648959LLU,18437735096338348031LLU,17437867388434382847LLU,18446716585918857215LLU,35184372088831LLU,18446744073693035520LLU,11529214973056122879LLU,18392700878181105439LLU,18446744073709551615LLU,34359738367LLU,18446744003916334078LLU,18014398467538943LLU,18213682792389085183LLU,2305843009213693951LLU,228629230387196LLU},{18356670844211556479LLU,9241386435364192319LLU,9222826678823155711LLU,18446181397825054716LLU,10367145604718526463LLU,17941813116037234687LLU,18014398299766777LLU,17582052945253367808LLU,13835049534067040263LLU,18446744073709551615LLU,18446744073709551615LLU,17870283321141886975LLU,18446744056538062847LLU,18446709988597431311LLU,193307877566435LLU},{18445618173265711103LLU,9223345648508665855LLU,18429292625153490432LLU,17870846271296634819LLU,18446744058677165311LLU,9799828425337176063LLU,18446744073709453055LLU,14987416609936637951LLU,9223372036846395391LLU,18446744073709519871LLU,18302769623122050559LLU,18446180565678817279LLU,14987961984882835191LLU,18445653358174733311LLU,136058121354783LLU},{13828302639722394623LLU,10375765769437777919LLU,16068421257992863743LLU,18446216308126121981LLU,18446708906517070847LLU,18158513671519404031LLU,18446730879568050687LLU,17861276122150338815LLU,13835058055282155775LLU,18446744039349846015LLU,144115188075855871LLU,18429839082230120448LLU,4610841577390602703LLU,16663292164272291068LLU,202112570228719LLU}};

static uint_fast64_t D[20][15] = {{1152921504606846975LLU,5224043213608819815LLU,18446744065530654990LLU,18446744073709551615LLU,18446744073709551615LLU,18443149173768323071LLU,7053129872549347327LLU,14123220257451413500LLU,8725998887501831LLU,18446744073709551615LLU,18306996137229286401LLU,18446744073709550599LLU,1098818688297074687LLU,18445618186704125967LLU,281474976710655LLU},{1152851135862669310LLU,7888849465378970727LLU,18446744036622843311LLU,18446744073709551615LLU,18446744073709551615LLU,18434141974513580031LLU,3816214361031049215LLU,13977753618520452527LLU,18434349997454253812LLU,15687853257122035123LLU,15845626911296960508LLU,18446744073708949492LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446695310546960381LLU,15779818376374779903LLU,9259400536363031390LLU,11529215046068369791LLU,13525918639585076586LLU,18446744073709551337LLU,18446744073709551615LLU,13693194667019993087LLU,17329461030531527583LLU,4562109713405824638LLU,12049889325680119687LLU,18446744073709157151LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{17293941701009473539LLU,13224820305665352600LLU,9187343711872182001LLU,17677522994433590912LLU,7412482904459837439LLU,30616497705455039LLU,18419229634507487168LLU,18446638204883628921LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,137438953471LLU,18446744073709486080LLU,18446744073709551615LLU,18014398509481983LLU,16999915964172599264LLU,18446686895548030972LLU,17883739552676788683LLU,17869702778713014255LLU,18419696053289222083LLU,18446744073709535115LLU,11931559088867115006LLU,18446744063682456229LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9223372032559939583LLU,18333024609483317205LLU,18437736874454811543LLU,18446744073709551615LLU,9223372036854775807LLU,17291988530418806654LLU,18230353588085850105LLU,9151244059033796479LLU,11270004922121185022LLU,6515195732805287935LLU,18446744066556777818LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14604279134558355455LLU,11096609938307608639LLU,18446744073709551228LLU,11421128520103184447LLU,13835196911558326407LLU,2305843009213693951LLU,1118017509055791135LLU,13974806050851750142LLU,7176739151588392447LLU,18446733325746700289LLU,18446744073709551615LLU,281474976710655LLU},{17870353690150305791LLU,18429568511304007679LLU,18446743970626519039LLU,18446744073709551615LLU,18446744073709551615LLU,9007199254740991LLU,18446744069414584320LLU,18302628885633695743LLU,18439988461667614713LLU,17563167165769039335LLU,16138646944836993022LLU,18446744073709002745LLU,17714205446820003840LLU,1125891305897973LLU,281474976710652LLU},{18446744073709551615LLU,18446744073709551615LLU,18446743936270598143LLU,7686750106917142527LLU,15955086603374189205LLU,18428729675200068438LLU,14658044151880566847LLU,9222645730704580310LLU,1129677119433321835LLU,16643525176891243469LLU,8997971910442023035LLU,18446744073709499627LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446730494919049215LLU,18428862029449134079LLU,9259400713610502143LLU,4611686018427353471LLU,18312194773967900608LLU,18446744073709551491LLU,18446744073709551615LLU,4544132024016830463LLU,17933614916556554232LLU,17328726564653760480LLU,4611685882028654543LLU,11270004922122208184LLU,17347936133375328255LLU,1125887005425648LLU,281474976710652LLU},{9458103963481008635LLU,18446181123822766079LLU,13852297847849877503LLU,18445530204282290175LLU,17796235532804554751LLU,18410715276160548287LLU,18446726616775835647LLU,18446708886669805437LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18410715276690587647LLU,17486958428159LLU,16140786595027484668LLU,281428900249599LLU},{18446603336204474039LLU,13256345503130418142LLU,18436284342149811965LLU,136930821688766232LLU,18446744073709289472LLU,3598083541981720575LLU,18437666488530761739LLU,18446251462430424035LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446726485130608639LLU,18446734993880252353LLU,18375812379577679871LLU,281452361002183LLU},{18212267583971737423LLU,18307132485246385713LLU,9216592446247368643LLU,18311634056161777383LLU,1143773567830458367LLU,14914109006998396912LLU,9239275268944685044LLU,18446735311967879167LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14411395659049467903LLU,18446740225290903487LLU,18230286242350616527LLU,281474949403450LLU},{247116878751727491LLU,18446744073709551552LLU,18446727031279321087LLU,18446743803126611967LLU,17437906968973737791LLU,18446744073699966079LLU,18428729676221881215LLU,18446744073709551615LLU,16140901064495857663LLU,1118018574208728095LLU,18446603472619962110LLU,8925843915497569791LLU,18446744073701190491LLU,18446742991377793023LLU,277590408888319LLU},{18416344514764466687LLU,18446744073709078527LLU,18445970017523597311LLU,18444922182942326783LLU,18428764311963812095LLU,18446744073708666879LLU,11529215046053297407LLU,18446744073173712927LLU,4611686018427387903LLU,18446708923663647743LLU,139752257216315903LLU,18316698785801043960LLU,18446743949625259239LLU,10934625546046275583LLU,280983065198591LLU},{16140901064495791295LLU,17437935695543661007LLU,17861161757674831423LLU,18014365383975219166LLU,18446744073709551615LLU,13683761950255742975LLU,9207606139624095723LLU,15852116534081093376LLU,18446462873602621191LLU,18446744073709551615LLU,18446744072635809793LLU,18446744069364252671LLU,18176514832264331263LLU,18446105769427287871LLU,228629229317879LLU},{4611686018427361255LLU,1152789563207794556LLU,18443081600477168120LLU,18412544812283591729LLU,18446744073709551615LLU,7205728350776590335LLU,18014121432551784446LLU,16717361542457212927LLU,18446744065127743743LLU,18446744073709551615LLU,18306996137229287423LLU,18446744071964720135LLU,1152920529630920703LLU,18446584438360961279LLU,267708532783503LLU},{18156798424116101119LLU,18446710983670890495LLU,16969563275672723455LLU,18446744073709518207LLU,18445055206702971907LLU,18446744073566895119LLU,18446744070488202879LLU,18406211677063217151LLU,18149787964958310399LLU,36028797018931200LLU,18302628886707437566LLU,4574671028197785599LLU,14109566526319197811LLU,15839159876573200383LLU,133582575960061LLU},{18334152145919016959LLU,18446320179764789247LLU,15348267529810477055LLU,18446744072904238079LLU,9241351800722571260LLU,18446216308124942335LLU,18446744073456319481LLU,18419722475945328639LLU,18302620098130608127LLU,18410750426736492543LLU,18446744072636858335LLU,17424343361051952127LLU,18226349166945094623LLU,7888054747075182588LLU,192379893573631LLU},{18014365524132003743LLU,18437736771312680899LLU,18144989567365676551LLU,17906311908995047375LLU,9223372036854775795LLU,11520766673585961984LLU,18429011077430771687LLU,16104309592401379327LLU,18149515294387994623LLU,36028797018963967LLU,18446744073709551614LLU,1152921429444919295LLU,18433216782146682879LLU,18441395207606833151LLU,103354042654332LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][15] = {{1152921504606846975LLU,5224043213608819815LLU,18446744065530654990LLU,18446744073709551615LLU,18446744073709551615LLU,18443149173768323071LLU,7053129872549347327LLU,14123220257451413500LLU,8725998887501831LLU,18446744073709551615LLU,18306996137229286401LLU,18446744073709550599LLU,1098818688297074687LLU,18445618186704125967LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,3],[2,6],[3,7],[4,5],[4,6],[4,8],[5,7],[5,9],[6,8],[6,9],[7,8],[7,9],[8,9]]\n", fout);
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
