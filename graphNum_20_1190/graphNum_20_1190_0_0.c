#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1190_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][17] = {{18446744073709551615LLU,281474976710655LLU,0LLU,18437736874455334910LLU,18446744073709551615LLU,18158513697557790719LLU,18446462598732873727LLU,18446744073709551615LLU,18428729675199676415LLU,16429131440643379199LLU,13835058055282163711LLU,9223372036049467647LLU,18446744073709551103LLU,18446744073709551615LLU,1023LLU,18446744073709551612LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1LLU,0LLU,0LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU,0LLU,0LLU,18446744073709551104LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,511LLU,0LLU,0LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15420325124116545543LLU,18014345717891464727LLU,17581993558716432123LLU,18302628885633695695LLU,15834090002616126442LLU,17865057031237136247LLU,63197LLU,18446744073709543424LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{4503599627370495LLU,18446462598732840960LLU,18446744073709551615LLU,16140901064495333379LLU,18411554958886172543LLU,18392698884871684095LLU,18446744073709551613LLU,18446744073709551615LLU,18446744073709551615LLU,18444448155983411199LLU,18406127838763450367LLU,13752865158630211565LLU,18446744073709514747LLU,8191LLU,18446744073709550592LLU,18446744073709551615LLU,16383LLU},{0LLU,0LLU,0LLU,18446744073709551614LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{17870283321405865985LLU,18429149551068175741LLU,9222245140314030079LLU,9007199254740990LLU,18446181123756130304LLU,18446744073709551615LLU,18446602991550005231LLU,18122445244567910335LLU,17761875864343543807LLU,18446744073709551327LLU,18446744073709551615LLU,18446744073709551615LLU,18446181123756195839LLU,18392700878181105663LLU,18446320761732827127LLU,18446744073709027329LLU,16383LLU},{18442240474082443263LLU,18446744073709551615LLU,18437736874451664895LLU,18446744073709551615LLU,562949953421311LLU,0LLU,18430981475013722140LLU,4607182410210082431LLU,18446744073709551614LLU,18410715276694781947LLU,18446741874686271487LLU,18446744073709551615LLU,562949953421311LLU,18446681951302459392LLU,18302628834094088063LLU,18446744004990599167LLU,16383LLU},{8444240174514175LLU,18338657682651611136LLU,18014391912412217151LLU,18445613774681405447LLU,18439988674261155839LLU,16717361266774572799LLU,281474976710655LLU,17870283321406128128LLU,18446744073709551615LLU,18428729623660462079LLU,18446744073709551615LLU,18446744073675999231LLU,17582052885124874239LLU,18446739675663047679LLU,16139775164521840639LLU,18446726532979197951LLU,16383LLU},{18446706690280128511LLU,18446462598733889535LLU,18444633011383963644LLU,17365809777148954623LLU,18275607287869472767LLU,18410142431132516347LLU,18446744073709551615LLU,576460752303423487LLU,0LLU,2305843009213693440LLU,18446735277616330752LLU,18446744073709551615LLU,18446744073707585535LLU,4398046511103LLU,18392700870660717568LLU,18442258060894797795LLU,16383LLU},{18444492237388643331LLU,17866905621622685695LLU,16140865605245860863LLU,13493202396905470LLU,18446744073709289472LLU,4611686018361324543LLU,18446744073709551612LLU,18446744073709551615LLU,18374686479668445185LLU,36028797018963967LLU,0LLU,18446744073709551584LLU,10304235943128793087LLU,18383764047670536191LLU,9218727699470346231LLU,17874769328847452161LLU,16383LLU},{18194392960858850303LLU,18433233274827440127LLU,18392700328261713903LLU,18446462529744928767LLU,16716798866846121983LLU,18439883121152229327LLU,18005602013806591LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,31LLU,18425914929727864832LLU,18446744073692905311LLU,17581769889712939007LLU,576460683583424511LLU,16380LLU},{216172782113783655LLU,70162564772095LLU,18446744073709549568LLU,4611686009837977295LLU,18446744073709550844LLU,18446744073709551615LLU,4611686018393866239LLU,18446742991377531391LLU,18446251492500306407LLU,18158513697557777983LLU,13833949747427409823LLU,18320643284141580031LLU,18446744073562693119LLU,18445477410307571711LLU,18446744073172681214LLU,18361173069449058007LLU,16323LLU},{18446727374860081151LLU,18446730041246089215LLU,18446744004990076927LLU,18446741883276013567LLU,36000752929341439LLU,18158375155334627327LLU,18446743936304147359LLU,18446744073709551615LLU,10354338372784095231LLU,18446532142591180799LLU,18446744073709551615LLU,8214534873600228863LLU,18438773576480849863LLU,17149707381026848718LLU,18446673705502244829LLU,6339203500123619327LLU,15934LLU},{18446744069431357343LLU,18446744070479937280LLU,68719476735LLU,18437739073478057790LLU,18446744073306898371LLU,18446744073709514752LLU,18446462736171794047LLU,18446744072636071935LLU,18446744071830241183LLU,16717361812769079295LLU,18446743524087955455LLU,18446743592136244223LLU,18311635809960198143LLU,18158232218554597375LLU,70368744177663LLU,17239707355499720508LLU,12799LLU},{14987978464672349783LLU,9241386435364205555LLU,18437667603342163967LLU,4611652620728663215LLU,18446744073709538547LLU,18446743936270602239LLU,18442238818370318847LLU,18446250521822990207LLU,18446744073709551615LLU,18446726485817806847LLU,17941353546471432191LLU,18446744073709551615LLU,144115187383795711LLU,18446743918486716408LLU,18294178022080675839LLU,18208046008187748351LLU,12275LLU},{4607183518311620591LLU,9223371972430266367LLU,18446744073707452416LLU,18302628877077266399LLU,18446743936807469052LLU,137438953471LLU,17573045745968189436LLU,9223372036854546175LLU,18446735279764013054LLU,18410732868876582911LLU,18446744073592094713LLU,18444492823651680255LLU,18446735827363692543LLU,9799780012465250311LLU,18446744038815039487LLU,11519785291825020927LLU,8143LLU},{18446744073696967807LLU,18444492273844486399LLU,18446744005023629311LLU,18446742012125247743LLU,2301339409579769919LLU,18446744073658957823LLU,18446743936807468991LLU,17870283322479869951LLU,18446744073707421823LLU,18446744039148093439LLU,549755813887LLU,18446744073676127712LLU,13254093647583903743LLU,18402266633637724159LLU,18446674254721183743LLU,17942325522279143679LLU,15935LLU},{18230570260803387391LLU,10367004935949647871LLU,18446744073692577791LLU,17582052945228791807LLU,18428166862685601791LLU,18446743936337707007LLU,1148417904709465087LLU,18446744073709551600LLU,8796093022207LLU,18446726550242975232LLU,18446744073709418503LLU,2251799813685247LLU,9222817882992738304LLU,9223372036839014392LLU,18446743794535087104LLU,9219431386375061479LLU,12272LLU}};

static uint_fast64_t D[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13907115649320091647LLU,18410848900069782335LLU,17230770009122930687LLU,13891353050624294908LLU,4102717671777238531LLU,17365810878843166328LLU,9201913710216478659LLU,18383676636495872480LLU,18429007294344325091LLU,1440258396224873464LLU,3903923163760831219LLU,18446744073709551207LLU,18446744073709551615LLU,16383LLU},{6359082673847140350LLU,13474372497153025686LLU,12352507267092225397LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,10789941716156383223LLU,17139414558301674966LLU,15846950714711422163LLU,13979173243358018990LLU,1997881789317180234LLU,16694121128084588663LLU,18446744073709540573LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18439538589186916355LLU,7459086882832383999LLU,16041714392874611663LLU,11505796877768982522LLU,15526954856428971626LLU,13742555793430932398LLU,18446744073709551613LLU,18446744073709551615LLU,18446744073709551615LLU,18403562535501432831LLU,17757475342321131519LLU,4385338273166262221LLU,18446744073709514675LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{12094866884385046525LLU,15960028767433693545LLU,8499266487452266170LLU,18434133444990074887LLU,8757249475421929471LLU,15238464232018558195LLU,18446301164826034191LLU,17545351027519088191LLU,7439062413538885631LLU,18446744073709551327LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18437736874454810625LLU,18446744073709551615LLU,18446744073709551615LLU,9186217339928969215LLU,16120350607712566269LLU,13805643300532186031LLU,13835058055277970301LLU,18439882708028489407LLU,2197756617144844284LLU,18446744073709502463LLU,14542820909948723199LLU,10823147282735364504LLU,18446744073709551614LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9187343239835811839LLU,12609989874384592341LLU,8786166621566605149LLU,18446462598732840963LLU,18446744073709551615LLU,18446744073709551615LLU,16203245011616137215LLU,9943103494208618495LLU,17581814986886346815LLU,17006485677484735567LLU,18446744073709548812LLU,7623596790974187519LLU,18446744073709551613LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,6953557824660045821LLU,12609283815568202133LLU,7912468121969612637LLU,7657245266436685818LLU,2208722561598340073LLU,13607475019168795436LLU,4510752368559651697LLU,17138131015780791477LLU,15814028746168252346LLU,18446744073709534062LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{6899514629131599871LLU,13474725509235308503LLU,16991777919192259957LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18429251921659035647LLU,1144617168046694399LLU,11525836416823066622LLU,18410715276690588152LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14555567043899170815LLU,11291628114073681693LLU,18446744004990599167LLU,16383LLU},{17329851366121668607LLU,18428796538985892924LLU,4573967288956108799LLU,18446744073709551614LLU,18446744073709551615LLU,18446744073709551615LLU,4557422403163947007LLU,18383685861144523260LLU,18306639904047653255LLU,9511602413006487103LLU,4603672295706263071LLU,1026820713992296700LLU,18446744073709493759LLU,18379892621823574015LLU,17833724690779046386LLU,18446744073709027328LLU,16383LLU},{18444435818646865915LLU,7483856680782921727LLU,16138684174176093180LLU,17307210192504487934LLU,18194408871198457855LLU,4610685448347448312LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,34969141830918143LLU,18446744073709549568LLU,8214288101422399487LLU,17211399466630839303LLU,18446744073709549484LLU,9155677296627267583LLU,18442258060894797793LLU,16383LLU},{18445750101367322631LLU,18313887884702121983LLU,17915311068785147663LLU,4609708338725781503LLU,9799832789150010560LLU,16206097705975942671LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18415218808467845119LLU,9294442201673080831LLU,18446744073675997215LLU,17377139095976804351LLU,18446744073709549919LLU,14553651455819927551LLU,18446726532979197951LLU,16383LLU},{18166732949961048063LLU,11421061791229149183LLU,17944586118154682147LLU,18445191458717175799LLU,16408865242324402175LLU,17574047931252489927LLU,266081302725471LLU,18446744073709551600LLU,1130965371977334783LLU,18446744073709551608LLU,18446744073709551615LLU,18446744073709551615LLU,18426477875386384383LLU,14555633995644673887LLU,15058910712760827677LLU,576460654768029695LLU,16380LLU},{1149506366687674367LLU,17437937757112251331LLU,14411035007973837052LLU,18439890519159992335LLU,9065746049896808447LLU,2269241366570070523LLU,18446689615646145724LLU,567522950997872255LLU,18446744073709518848LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,10304235947423694847LLU,18437740291436832767LLU,4586894228763312127LLU,17874769288944418815LLU,16383LLU},{18446744069414774783LLU,18446730875543486463LLU,18446744073709551615LLU,17798225727368056831LLU,529964071711743LLU,18446744073709547520LLU,18228319491782082079LLU,13326089724738142195LLU,9367487222787317759LLU,9223372032564002811LLU,18383693678926363134LLU,18446743525002313699LLU,18303085764657676224LLU,17937825702216450047LLU,18446744073709551439LLU,16716130363709587455LLU,13438LLU},{288230376151711623LLU,18446532967464435456LLU,18446744073709551615LLU,1152921504606846735LLU,18446321758164221888LLU,17230772071227588607LLU,18446744073709551612LLU,18446744072635809807LLU,18374678783089180544LLU,18425338764160138759LLU,18446743523953739775LLU,18444773748872447999LLU,15852384806665913343LLU,13816515886913153787LLU,18446744073709550839LLU,18379188017714423583LLU,15319LLU},{18374669780838735743LLU,18446743030015717631LLU,18446744073709551615LLU,18014398509481901823LLU,18446742004070087743LLU,18446603469381697535LLU,274719577269595135LLU,9223370938416889855LLU,18442249134881634431LLU,18446479125766995967LLU,18445618723558522753LLU,17296039734298148863LLU,4035197211195473919LLU,7456254510810693574LLU,18446744073709551612LLU,6844765543648386807LLU,16299LLU},{18410715276690556927LLU,18446744005056397119LLU,4573968320000114687LLU,18230571291595706366LLU,18446743936278790143LLU,18446744073709551615LLU,17311616962073198591LLU,17879290519721345023LLU,18446735277616562175LLU,1152921504606846975LLU,9223362759725350904LLU,18444492273929420768LLU,18446735344188129279LLU,9232375935426232319LLU,17834219200428638207LLU,9799305023576832888LLU,5887LLU},{18302628885633629919LLU,18446727580993130480LLU,18446673771553947647LLU,17870249923740302783LLU,18446711088356508659LLU,18446744073709551615LLU,18446742003803750399LLU,18446182223251242992LLU,9227875636482115487LLU,17870283321405472767LLU,17871409212857120895LLU,1152921504575289855LLU,18446638485410414528LLU,18439706957955727359LLU,18437798717688905667LLU,18283483639414893999LLU,11646LLU},{18446479366033354751LLU,1143650367800606719LLU,18374756848415801312LLU,18446216307599433727LLU,18428201780367065087LLU,18374827084015960000LLU,18446728680538888063LLU,18446744073709551615LLU,9223363376321396734LLU,18442505455578095104LLU,18446744073709551615LLU,18444526976694747135LLU,18419293391532523583LLU,11240949485544668729LLU,17302829768324398143LLU,12679532893706125311LLU,15317LLU},{4607463889737612719LLU,18444492273894883087LLU,72057527463835679LLU,18438298167087725406LLU,2301339409586077644LLU,72057594037923903LLU,18446480062044683964LLU,17870846270302355199LLU,18446744073709551615LLU,17262297368286167039LLU,576460211020087295LLU,18446744073709551584LLU,18334154079762120703LLU,18446739947185496575LLU,1152859897092632575LLU,18113467479209540476LLU,5887LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13907115649320091647LLU,18410848900069782335LLU,17230770009122930687LLU,13891353050624294908LLU,4102717671777238531LLU,17365810878843166328LLU,9201913710216478659LLU,18383676636495872480LLU,18429007294344325091LLU,1440258396224873464LLU,3903923163760831219LLU,18446744073709551207LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,4],[2,6],[3,7],[3,8],[4,7],[4,8],[5,6],[5,7],[5,9],[6,8],[6,9],[7,9],[8,9]]\n", fout);
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
