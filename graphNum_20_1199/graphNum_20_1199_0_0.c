#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1199_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,127LLU,0LLU,0LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,144115188075855871LLU,0LLU,0LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,0LLU,0LLU,0LLU,18446744073709551488LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{0LLU,0LLU,18302628885633695744LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18437736874454810624LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,576460752303423487LLU,18446744073709535232LLU,18441114126960162731LLU,18329509324465890807LLU,17257650826982162687LLU,13814509866586209275LLU,18410574530813210557LLU,14289355078523LLU,18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{9007199254740991LLU,18446462598732840960LLU,288230376151711743LLU,18446744073709518848LLU,13830202598763100863LLU,18435309152780673279LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9222228269863043071LLU,17870239888012205951LLU,15848165722907180543LLU,18446730810179305471LLU,4294967295LLU,18446744073642442752LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,281474976710655LLU,18302628885633695744LLU,18444545050454032383LLU,18446730879570018289LLU,18302622262794125311LLU,4610586506799628287LLU,17942200177955700735LLU,18446744073703260159LLU,18446744073709551609LLU,18446744073701687295LLU,17870283321406128123LLU,18446744065117517815LLU,18446744073709551615LLU,67108863LLU,18446744073708503040LLU,4194303LLU},{18446744073675997185LLU,18438862772751040511LLU,18410715250920767679LLU,17592186044415LLU,18445618173802708992LLU,1152921504606846975LLU,18446744073684385664LLU,18446744073709551615LLU,18446743798705815551LLU,18446744071595618815LLU,18446743575501684735LLU,18446711086749843455LLU,14980845928447LLU,18446744073709551600LLU,18442662685607722623LLU,18446744039350337523LLU,4194303LLU},{17320844166900482047LLU,17293611462868336639LLU,18441111275640455167LLU,18446744073709551615LLU,1125899906842623LLU,18158513697557839872LLU,17294947300778426495LLU,576460477424467967LLU,18374686479671619582LLU,18439988674268467079LLU,18446744073709551615LLU,1152921498164396031LLU,18446744072887468031LLU,10376293270878683151LLU,18446743936220266495LLU,18445618208162446847LLU,4194303LLU},{17908845393215487LLU,18428729675199938560LLU,574771833697992699LLU,18446744073172680640LLU,18446744073709551615LLU,18446743558313474559LLU,8796093022207LLU,18428729675200069632LLU,18446744073709551615LLU,18446744022169485311LLU,18338656583141031911LLU,18445899597238763399LLU,18446735277587169279LLU,17870283325650763775LLU,17221756176824270847LLU,18375631441196187615LLU,4194303LLU},{18446744073709551363LLU,13834776580305584127LLU,18446717685430484479LLU,9225623561790521407LLU,18446744065119617023LLU,18446744073709545471LLU,18446744073709551615LLU,18014398509481983LLU,0LLU,18230571291592097664LLU,18446737476606230527LLU,18446743867551121407LLU,18444527458267954959LLU,576460752303423487LLU,18446743523886628864LLU,13907115649287583743LLU,4194303LLU},{18446744072702853119LLU,18446743519654575869LLU,18446744073709551615LLU,18154010097930469375LLU,16143047311067398047LLU,18443313528711413759LLU,18300377085820010495LLU,17292133715215893497LLU,18445688538503577539LLU,111LLU,18446744073709486080LLU,18446744073709551615LLU,17541203889259282431LLU,7924632672419184139LLU,18446744073692576126LLU,4465318788876730367LLU,4194288LLU},{18446744073708896255LLU,17870840773759464939LLU,18446743528248705023LLU,17870283218326454271LLU,18446743968616873983LLU,18446744073709551615LLU,18446744047939518463LLU,18446740710737330175LLU,17565164446651726911LLU,18446744073709551615LLU,65535LLU,18446744073575333888LLU,5691986979042885631LLU,18421780761712525311LLU,18446744005054300137LLU,18433233267969752833LLU,4193295LLU},{18446743542207348735LLU,576460709353750527LLU,18446744073705389952LLU,18437736874195288063LLU,2305843009213693567LLU,18446744073705373568LLU,18442240473876922367LLU,16140901064495857639LLU,18446740710750158847LLU,18446744073709551615LLU,18446744073709551615LLU,134217727LLU,18437648913524588544LLU,16140899947803853311LLU,17874505514776242175LLU,17582035627946278911LLU,4129791LLU},{18446744073706323839LLU,18446717135469137565LLU,18446744071562068095LLU,13834635825645600502LLU,18446734315441094651LLU,18446744073709551615LLU,18446532963186245613LLU,18302598095969439743LLU,10375449116531032015LLU,18446462598737035259LLU,18446744073709551615LLU,17798226002246107135LLU,17870283312814094327LLU,18409299105714012158LLU,281474972385246LLU,4591419809817690110LLU,3995646LLU},{9079239805342054383LLU,18446743863255105535LLU,15996785878567485439LLU,18372980054805182463LLU,16149908263750594551LLU,13835053637912494079LLU,9186490023107624447LLU,18158513697557839615LLU,18446713284158554110LLU,281474976710655LLU,9223380832939868160LLU,18446744073709551611LLU,18446744073709551615LLU,18446744073701686815LLU,18446744073709517823LLU,17149583995205320705LLU,3407825LLU},{1152919234582380799LLU,9221120237041090432LLU,576214444518798334LLU,9223370387552731134LLU,18338657682648465408LLU,1152921504505986553LLU,1152921092281073660LLU,18446744073575333888LLU,18446744073709551615LLU,288230375748926463LLU,18442803285588967423LLU,18446717649997004799LLU,18160765497371263231LLU,18446181398632921023LLU,18427600476489908223LLU,18445618172762509303LLU,2871291LLU},{18445794095629631487LLU,18442240472205099135LLU,18446744073558544383LLU,18446744071025196545LLU,18445618173806903295LLU,18446189404453073919LLU,18446744073155900291LLU,18428729675334287359LLU,18446743798705291265LLU,18446744072098674687LLU,18446743782725517311LLU,18446744073709494175LLU,288230376151711743LLU,8647474234051788784LLU,18444492273358995008LLU,9153566209344536575LLU,2031423LLU},{17573063338182901759LLU,16726369016054022143LLU,18446741357146931199LLU,18446462478741733375LLU,18446743144285339647LLU,18158513699705323519LLU,17365739404445664255LLU,18446744073709551615LLU,18446744073709551615LLU,18439707201439240191LLU,9223372036854775807LLU,3963202849881456640LLU,6341068275337658367LLU,18446743863264542718LLU,576460547218735103LLU,9188609877231009038LLU,3996734LLU},{17574171645906489119LLU,18014117309383180160LLU,4611686016548337151LLU,9367205737068728318LLU,18446744073705365503LLU,8935704610656480767LLU,17365739422422519804LLU,18446744073575334399LLU,35184372088831LLU,18446466996777238400LLU,18446739674824179711LLU,18446744073575399423LLU,18192572169739829247LLU,18446185311886114815LLU,9223371985248124927LLU,16140338113504346110LLU,3013886LLU}};

static uint_fast64_t D[20][17] = {{1184622056863105283LLU,18446231336600623926LLU,498614226978317823LLU,11272570041402327040LLU,18445024274307598305LLU,989931764916929023LLU,3906902013996138496LLU,8133060297541811326LLU,13618844865899778044LLU,18446744073709551537LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{17275808170593222654LLU,13059825756576523465LLU,18425834999806132050LLU,18446744073709551615LLU,18446744073709551615LLU,17870283321406128127LLU,17293810824036515839LLU,18423059316009707435LLU,7735625987025974695LLU,14879464264799682303LLU,13634349869853242323LLU,18337109037365964593LLU,18446734147999163235LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18433057919962775293LLU,5387431054241955839LLU,18113154108710509229LLU,9223347047132889087LLU,3841217224525576895LLU,18399279803143995093LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8922703157666972159LLU,7488816639392325246LLU,10650965823062243839LLU,18446737268736114430LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18302628885633695743LLU,16397571058883887103LLU,14607246648585928030LLU,18080737331661602602LLU,15692775309386448895LLU,10337368533867584469LLU,15539017294493350491LLU,13091320724952448846LLU,15770321638173535661LLU,7905413286990894798LLU,18446743212207332765LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,144115188075855871LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,2304734701492895743LLU,17906090006296879103LLU,15561605734701301599LLU,4465855145510436856LLU,17509942574650085167LLU,17430617758504058095LLU,18446743970420596703LLU,17740355952202219519LLU,5543550068090022796LLU,18446744073709180573LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18444527458267955199LLU,16915504187624652784LLU,72049865962913706LLU,18446735277616529408LLU,18446744073709551615LLU,18446744073709551615LLU,16658600602581860351LLU,11498393527377689081LLU,9169095744760571896LLU,6338798593423962609LLU,18446744071478198812LLU,12903194005671510015LLU,18446744073708874082LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16397606243255975935LLU,11521931865584842783LLU,18429591486157807743LLU,17998635910786187263LLU,10367848758777017217LLU,18306920884251648243LLU,18446744073705357391LLU,18446735290736312319LLU,14987979285143232415LLU,12107945739305123647LLU,706388123738684899LLU,18446744073657570419LLU,18446744073709551615LLU,4194303LLU},{17311836967612186623LLU,16518956957904797695LLU,18438295769378684915LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17293829593050447871LLU,18014398509481983LLU,9223342295279992830LLU,18437987030527311744LLU,17329782096889118471LLU,63331783844822115LLU,18446735276546981887LLU,9799832518575259647LLU,5543904523174489087LLU,18445618208162348191LLU,4194303LLU},{17293822569102704639LLU,13826598960581551305LLU,18392621683279118366LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152919159522689023LLU,18446481274261409791LLU,14119066306649276175LLU,2089670224955179007LLU,18446744056529684479LLU,18446708992416677887LLU,18446743532541544391LLU,18316816708800610303LLU,18442308093033971212LLU,18446744039350065137LLU,4194303LLU},{18442089521483874049LLU,11167801175971987455LLU,18401677006499413167LLU,9223384740138188799LLU,7466968182180282367LLU,18194534246600621982LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18167270757816573439LLU,10375800891469412607LLU,18383687076907049983LLU,18444507238635667200LLU,18446744071489936095LLU,13537080740344233983LLU,13907115649286927226LLU,4194303LLU},{18446614118326927103LLU,8036673535042650111LLU,18444736245187861497LLU,9223369252806787071LLU,17906294696326463472LLU,18446743525596921825LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16422375972621247487LLU,9079819373326106592LLU,4034108159088918400LLU,6338816475490676991LLU,18446744073647482684LLU,16587868892395732991LLU,18375631441196166599LLU,4194303LLU},{13183654057836010423LLU,134087754314727LLU,8070450532247928704LLU,16104801898724350811LLU,18446176605449484285LLU,15978487520438525951LLU,13240547720092980918LLU,9142162657768374143LLU,17437933908818599935LLU,18446744073709551549LLU,18446744073709551615LLU,18446744073709551615LLU,9223372036854775807LLU,18428588937711222783LLU,18446462598797836271LLU,17861260724416806911LLU,4151663LLU},{16104872250321124731LLU,18446656097612423103LLU,17792436798643781631LLU,13818018648448548070LLU,993812480523787LLU,17293822569102704512LLU,18438223614273650509LLU,14265415427540647904LLU,13763000392658710527LLU,18446744073709551587LLU,18446744073709551615LLU,18446744073709551615LLU,18433127721711173631LLU,14843862696775893003LLU,17874786921016713727LLU,13402710326391078911LLU,4171763LLU},{8789583363615516623LLU,18446742080292125816LLU,11529214498040702463LLU,17365035610972088253LLU,18446744071566004215LLU,4607679277792485887LLU,8970748213556406779LLU,18158513628972318975LLU,18428760186618379264LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14014357615446851583LLU,9214861747448446975LLU,18446744073708568440LLU,9216616633984876289LLU,4193948LLU},{4395495661290648551LLU,18446603078521520127LLU,14987979559889010687LLU,17744182531839751135LLU,18445758910888206847LLU,11529215043920986239LLU,18383693678926363839LLU,4595923368191786527LLU,18433198159174827262LLU,18446744073709551519LLU,9223372054034644991LLU,14987979559889010687LLU,17203029845860974399LLU,13542286661739626487LLU,18446744073675415547LLU,16717223278334181375LLU,3366863LLU},{17867398202890886975LLU,18446711087035302791LLU,9223372036854775807LLU,10367286342206856818LLU,11529213948700393087LLU,18414725882791854079LLU,17577549345627035620LLU,16140865948709289959LLU,9241386422378169343LLU,18446744073709551615LLU,18446744069649465343LLU,18374686479803752351LLU,4457367362445770751LLU,16077356832997244414LLU,18446744073702209223LLU,18419722462229954559LLU,3993983LLU},{18445749831193329663LLU,18338657682384355327LLU,18430981062458867687LLU,18446739603583794751LLU,16717361816799281151LLU,18446181671898183583LLU,18446742406321599487LLU,18014398509481983LLU,18446744073709027328LLU,18446739744381984767LLU,9367485025903179807LLU,18375812306563956863LLU,18446744056563236863LLU,576460751829196543LLU,11096816692397866944LLU,9150952566052159295LLU,2031423LLU},{18442237069045530623LLU,143868712787640319LLU,18446463146877812734LLU,18446742003483148287LLU,9088264048033660927LLU,18194542494450728952LLU,18446743556097966079LLU,18446744073709551615LLU,9223342295279992831LLU,4398044397440LLU,18442244872127119359LLU,72057593905807355LLU,18446744073709289472LLU,18446744071560393631LLU,9191842458537765887LLU,13978590192957636862LLU,2871291LLU},{1152921504581677539LLU,13835057780672577535LLU,14285180523507613598LLU,18303744615057977807LLU,18445635757398810639LLU,10376293541461622783LLU,1152351545264177055LLU,18428764859572157952LLU,18446708889337987071LLU,2089670227098468351LLU,18446744073709488127LLU,18446743901910859775LLU,18414955010706902799LLU,17942336792275451891LLU,18446530218697883711LLU,16285016235356444671LLU,3346419LLU},{18446730453533589503LLU,18442240474082066431LLU,18302910360606465921LLU,18445602780432302031LLU,16283891452176498687LLU,18446744071692353415LLU,18446172877281558431LLU,18428764859572158463LLU,18446744073709551615LLU,18446744072098674687LLU,9227875348712980480LLU,18446744073709551615LLU,18446726481523769343LLU,17942340915437358705LLU,17903783241144336383LLU,18410594656828014591LLU,1523703LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][17] = {{1184622056863105283LLU,18446231336600623926LLU,498614226978317823LLU,11272570041402327040LLU,18445024274307598305LLU,989931764916929023LLU,3906902013996138496LLU,8133060297541811326LLU,13618844865899778044LLU,18446744073709551537LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU}};

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
        A[i][16] = A[i-1][16] & C[i][16];

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
        A[i][16] = A[i-1][16] & D[i][16];

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,6],[2,7],[3,6],[3,8],[4,5],[4,7],[4,9],[5,7],[5,9],[6,8],[6,9],[7,8],[8,9]]\n", fout);
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

