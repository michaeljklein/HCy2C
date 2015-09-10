#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_27_924_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 26;
static uint_fast32_t endhere = 0;
char str[37] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[27][16] = {{18444492273904222209LLU,18374686479671640063LLU,268435455LLU,18446735278152351744LLU,18446673707112923139LLU,9223653520421945343LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13835058055282163775LLU,1073741823LLU,18446743798848421632LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU,0LLU,0LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0LLU,0LLU,0LLU,0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{0LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2297396697824630783LLU,16284479690865893886LLU,18309384276887469599LLU,1729241518910207999LLU,254LLU,18446744073709551608LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,72057594037927935LLU,0LLU,18446735277617577984LLU,18446744071562199039LLU,9223934978218786815LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13835058055282163719LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{17293822569102704640LLU,72057594037927935LLU,8914729741655735296LLU,18446744073709270907LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,11473469390900663807LLU,4175846206039079411LLU,17552216544405091231LLU,10808463180496369151LLU,18446743798831644915LLU,4611686018427387903LLU,18446744073441116160LLU,18446744073709551615LLU,65535LLU},{1152921504606846975LLU,18374686479671623680LLU,18446744073709551615LLU,8796093022207LLU,18446744073709486080LLU,18446462607322775551LLU,18446744073709551615LLU,9216614987743526843LLU,16716939312251267070LLU,18338582909415063167LLU,9204227065111101371LLU,274877906942LLU,18446744073709551608LLU,18158513697826275327LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU,0LLU,18446744073709289472LLU,18446744073709551615LLU,17870142549549645793LLU,18410715145693560703LLU,9223338501748129783LLU,18438297728464068577LLU,18446744073709551487LLU,17524406870024074015LLU,192153583922184191LLU,18446744073709551104LLU,65535LLU},{2305843009205305345LLU,144115188075855840LLU,18446744073709029374LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18442240748951699711LLU,4611686018427387903LLU,18446744073709543424LLU,18446744073692774911LLU,65535LLU},{17293822569111093247LLU,18446744073709551615LLU,18446744073709550593LLU,18446744073709551615LLU,65535LLU,18446744073709289472LLU,18446744073709551615LLU,13797894285170294759LLU,8932819388927540215LLU,17852242499182524351LLU,13828301004358975463LLU,18446743798840033271LLU,17831852604585899903LLU,288230375883284479LLU,18446744073709551104LLU,65535LLU},{18444492273904222209LLU,18446744073709551615LLU,8914729741655736319LLU,18446744073709270907LLU,18446673704965439487LLU,281474976710655LLU,18446744073709535232LLU,18446744073709547751LLU,18446727477955919871LLU,18442495560526594047LLU,17358859231625638119LLU,18446744073701162751LLU,10760600709663905151LLU,288230376151703551LLU,18446743798848421632LLU,65535LLU},{17296074368916389887LLU,18446744073709535263LLU,18446744073441639425LLU,8795558248447LLU,70368744177662LLU,18446744073709289472LLU,18446744073709551615LLU,12928487299522936831LLU,7725573313655958326LLU,3945152409214334643LLU,13835058001259528191LLU,4503324766240566LLU,18446744073709551580LLU,18446744072904261631LLU,18442240748960087807LLU,65535LLU},{18444492273904222209LLU,18374686479671640063LLU,18446744073709551615LLU,18446744073709551615LLU,18446673707112792065LLU,9223090570467999743LLU,18446744073709535232LLU,18446744073709548459LLU,18446730518792765439LLU,18443274014805458943LLU,17558192168529212331LLU,18446744073701162751LLU,18446744073709551611LLU,1073741823LLU,18446743798848421632LLU,65535LLU},{1157425104225861631LLU,144115188075839520LLU,18446744073441641474LLU,8795558248447LLU,70368744177662LLU,18446744073709289472LLU,16383LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8389119LLU,9223372036854775804LLU,18446744073441124352LLU,18442240748943311871LLU,65535LLU},{0LLU,0LLU,0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{1733885856533479423LLU,144115188075847728LLU,18446744073576121859LLU,18302637681460379647LLU,70368744177663LLU,18446744073709551608LLU,18446739675663056895LLU,4095LLU,18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,17874752009408545279LLU,9223372036854775807LLU,18446744073707470784LLU,17874752011539186687LLU,65535LLU},{17868871203783940717LLU,18406202726317744111LLU,17834245726012177918LLU,144108207948136439LLU,18446688233135617242LLU,11127608366983282695LLU,4398046498102LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,571992064309395455LLU,18446744073709551612LLU,18446744073443205183LLU,571992337031495679LLU,65532LLU},{18446743936278986497LLU,18446744039349829631LLU,18374686479940059135LLU,18446744005526945791LLU,18446743528232058371LLU,18375247247715074047LLU,18446744073709551488LLU,18446744073709551615LLU,18446744073709551615LLU,18442241573593808895LLU,18446744073692774400LLU,18446744073709551615LLU,18446744056529682495LLU,288212785039409151LLU,2305843007082987518LLU,65475LLU},{11441394990773043455LLU,15636497940590099261LLU,72057594017966003LLU,18444430769923293184LLU,18157599451508572671LLU,9295150346416422911LLU,18446744072635400319LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13835058072462032895LLU,18158531289743884287LLU,18361175408059088641LLU,64575LLU},{2238289014802644991LLU,16285016252571712574LLU,18446744073693792195LLU,17580935841409138687LLU,18374756848415801342LLU,18446744073709354767LLU,2305288855219093503LLU,18446462598732845055LLU,17592186044415LLU,18446744073709551600LLU,1152921504606846975LLU,16683477198329147648LLU,9223372036854775805LLU,18446744073568923452LLU,18376830802214904831LLU,62079LLU},{17942339265669627379LLU,2305841085060080625LLU,1152920409272516159LLU,18303754644645478399LLU,72056468722154471LLU,18299246684650078200LLU,18446739675797257977LLU,281474976710655LLU,18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,17906279131062931455LLU,18446739950540686335LLU,16717150646140272579LLU,17942307925699469307LLU,53235LLU},{9169328704423853839LLU,16717361782447930622LLU,18374687579170643919LLU,17869227725793787903LLU,18375811864166661663LLU,18379188017651777343LLU,18446251492366614407LLU,18446462598749618175LLU,72057594037927935LLU,18446744073709551600LLU,18446744073692778495LLU,17266728948931097599LLU,18446744056529944575LLU,2305825485742833532LLU,9169256821301176318LLU,62415LLU},{6894978036102165455LLU,17726029594336689855LLU,18446463698239215595LLU,18446514537761865472LLU,18438574599031482270LLU,17568515344958291967LLU,2305843009205696999LLU,18446744005006852095LLU,18446744073709551615LLU,18446744073709551615LLU,281474959937535LLU,18435484387408608000LLU,18445622571782373373LLU,11524991890491404286LLU,9198601662967576551LLU,47981LLU},{18266599959663738683LLU,12682136516851529210LLU,18374967890181799775LLU,15550085035682955263LLU,14348467991882759799LLU,18391573294595699519LLU,18414726262770630557LLU,1152640098349613055LLU,72057594037927680LLU,18442240474350616560LLU,18446744073709551615LLU,12591707195037833215LLU,18446744056596775935LLU,8646894778970733941LLU,15960399736476512254LLU,30683LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,18446744073709551614LLU,18446744073709289487LLU,8796093022207LLU,18446744073709551615LLU,4294967295LLU,0LLU,0LLU,571992064309395200LLU,18446744073709551612LLU,18446744073443205183LLU,571992337031495679LLU,65532LLU},{6606752608958641623LLU,8502671026550730423LLU,1152656590951536363LLU,18320413887647710991LLU,4603517660474895279LLU,17714886799750332408LLU,18446739710014782187LLU,18446744005006852095LLU,18446744069414584575LLU,18446744073709551615LLU,18446744073709551615LLU,18005364370548145151LLU,18445684419315122175LLU,12678546868547321806LLU,18135968739575625707LLU,40935LLU},{13571632532501466939LLU,10016146274936549752LLU,18374967890162888471LLU,18434879190998188287LLU,15816016945921859191LLU,10320876464226959359LLU,18446744055388555165LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13836183938076230655LLU,8363168002467692543LLU,18185535053159726878LLU,29951LLU}};

static uint_fast64_t D[27][16] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,174083477002518527LLU,7243828894392909822LLU,18446744073709289480LLU,4450727903231LLU,4095LLU,17587891077120LLU,4502500384112640LLU,1152921435904147455LLU,8388864LLU,9223372036854775804LLU,18446744073441124352LLU,18442240748943311871LLU,65535LLU},{17290775628227805182LLU,18343328838182977503LLU,1765718992614849533LLU,18446744073709060376LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1810889161814709630LLU,2419019583212560786LLU,10526458869939343897LLU,1548771980660434302LLU,18446744073709551506LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{1155968445481746433LLU,103415235526574112LLU,16681025081094702082LLU,18272660596708572903LLU,11202915181464190979LLU,9223653520421945335LLU,18446739622981648384LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446735277617577983LLU,17127048643254222847LLU,9223653503241639258LLU,2635252968296710143LLU,17789057960214658773LLU,16099804435545775981LLU,7926007062622203382LLU,18362844013052911317LLU,18446744073709551469LLU,13835058055282163719LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,174083477002518527LLU,8563524320553336828LLU,9223372028264753837LLU,15811495556140744703LLU,1144193649504813995LLU,16212399745817108734LLU,18303662418035473935LLU,264369598906413995LLU,254LLU,18446744073709551608LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU,18446744073709486080LLU,18446462598733103103LLU,7905750003434323967LLU,17798067359029657497LLU,18406211236560043887LLU,8070337763579883510LLU,18418026578043314073LLU,18446744073709551471LLU,16909515400900422287LLU,18158513697826275327LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,72057594037927935LLU,8914729741655735296LLU,18446744073709270907LLU,17127048643254222847LLU,9223653511831311706LLU,13176247038571937791LLU,18383678282004561143LLU,2301899026410184689LLU,17437084475975004671LLU,18228266161706859767LLU,18446744073709551601LLU,1537228672809129335LLU,18446744073441116160LLU,18446744073709551615LLU,65535LLU},{1152921504598458368LLU,51152499712163808LLU,4148722575628305406LLU,18446744073709130553LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,6752544411841418623LLU,13104161548394149339LLU,15804679047335631709LLU,6160739562446910847LLU,18442240748951699675LLU,4611686018427387903LLU,18446744073709543424LLU,18446744073692774911LLU,65535LLU},{18443697132834652159LLU,18436291526546669535LLU,16063740490695573501LLU,18446744073709481438LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,12928487299522936800LLU,7725573180511972150LLU,3945118324351841971LLU,13826330146677592032LLU,18446744073709551414LLU,17524406870024074015LLU,192153583922184191LLU,18446744073709551104LLU,65535LLU},{1152921504606846975LLU,18425838979383787488LLU,13680736907682120703LLU,18446744073709411261LLU,18446744073709551615LLU,18446462598733103103LLU,7905750003434323967LLU,9004894115591061279LLU,17856630822149093327LLU,14951704263944818556LLU,9160306235888762655LLU,18442240748960088015LLU,17216961135462248175LLU,18254590490055802879LLU,18446744073692774911LLU,65535LLU},{1152921504606846975LLU,18446744073709535232LLU,18446744073441117183LLU,8795558248447LLU,18446744073709551614LLU,18446744073709551615LLU,7905750003434323967LLU,8135487129943703551LLU,16649385605870970638LLU,1044834076315291248LLU,9223371972027613183LLU,274877906702LLU,18446744073709551564LLU,18446744072904245247LLU,18442240748943311871LLU,65535LLU},{18446744073709518849LLU,18425838979383787519LLU,4148722575628828671LLU,18446744073709130553LLU,18446744073709551615LLU,262143LLU,18446744073709535232LLU,18446744073709547551LLU,18446726618962460671LLU,18442275658187931647LLU,17302550492387340319LLU,18446744073709551359LLU,10145709240540253439LLU,18254590490324238335LLU,18446743798848421375LLU,65535LLU},{18446744073709551615LLU,72057594037927935LLU,18446744073441116160LLU,18446744073174777855LLU,17127048645401640959LLU,18446744073709376858LLU,2635252968296710143LLU,17302550424204738559LLU,2234348360866733825LLU,144114097154097648LLU,18446744005526945791LLU,18446744073709551361LLU,9223372036854775751LLU,18446744073441124352LLU,18442240748943311871LLU,65535LLU},{18445948932648337407LLU,18415386432220905471LLU,1765718992615374847LLU,18446744073709060376LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709547520LLU,18446726485818474495LLU,18442241573325438975LLU,17293822637805404160LLU,18446744073709551615LLU,13835058055282163775LLU,1073741823LLU,18446743798848421632LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,174083477001469951LLU,7243828892245360636LLU,9223090553287606280LLU,4450727903231LLU,16635854911894841985LLU,16027724490496990829LLU,7920285203770207718LLU,16897972093049117313LLU,18446744073709551469LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18444625897282574957LLU,18375796715773902847LLU,17298309672029126655LLU,18446737093849780208LLU,18446688233135617243LLU,11127608366983544831LLU,18446744073709538614LLU,18446744073709551615LLU,18446726485818474495LLU,18442241573325438975LLU,17293822637805404160LLU,18446744073709551615LLU,13853006209285880895LLU,15581544105694461951LLU,576460534182838068LLU,65532LLU},{18446654991457320959LLU,18445792442764754943LLU,2301655046732906495LLU,18446744073709547807LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0LLU,18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18428795919705834495LLU,2865199969088831487LLU,17874786864292954059LLU,65535LLU},{11443646653147807743LLU,15708555500268288829LLU,18446744073689589683LLU,7706723289646759935LLU,17941285384281391102LLU,18446744073709305033LLU,284224303522136063LLU,17294104044062642175LLU,18374704067563749375LLU,18446744073709486095LLU,1152921435904147455LLU,15232103633598967040LLU,9223372036854775804LLU,18446744073496536731LLU,18357601993108020223LLU,64575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,10911799684653645823LLU,7460212782739226623LLU,18446744073709536062LLU,18162524219841183743LLU,1152640029646913535LLU,72057594036879360LLU,268435440LLU,18446744073692774400LLU,3214640440118973439LLU,18446744073709551615LLU,18446744073654139236LLU,2304913372128946175LLU,65475LLU},{18445053161736486129LLU,18383691514254475263LLU,72056494794735615LLU,18446739465745530879LLU,18446707208880224739LLU,13614797164177260543LLU,18446744073709543032LLU,18446744073709551615LLU,18446744073709551615LLU,18442241573325438975LLU,18446462667452313600LLU,18446744073709551615LLU,14123284050566971455LLU,16212694708097384447LLU,10376293397462777721LLU,53234LLU},{18446315159484881775LLU,18438847351075373055LLU,18379173586624577535LLU,17582050432698486768LLU,18446723972649170654LLU,15812057887456165647LLU,2305288855353290167LLU,18446744073709551615LLU,4294967295LLU,18446744073709551600LLU,281474959937535LLU,16715004319983533824LLU,18176462109259595773LLU,16086000043598802751LLU,8644553853095247798LLU,62077LLU},{18372995568226516223LLU,16077848505049152509LLU,72057594021117887LLU,7995010634249994239LLU,17942304080680417791LLU,13618737934113914105LLU,16425186940669648511LLU,17294104044079415295LLU,18446744069415632895LLU,18446744073441116175LLU,18446462598749618175LLU,15815355384200916991LLU,14123284050567233534LLU,18230307408728422107LLU,17220478402574081913LLU,52670LLU},{18228882441633251323LLU,11466164651284362233LLU,18446744009234612031LLU,14971086662064472063LLU,13907080455284031479LLU,13833791379231207679LLU,18411278192418480125LLU,281474976710655LLU,18446744073709551360LLU,18442240474082181135LLU,18446744073709551615LLU,11420699819303489535LLU,14123288431433860095LLU,17654110526381882611LLU,14771377830766288767LLU,28155LLU},{16136362417935315199LLU,18302488182505078719LLU,72057594036877307LLU,9151295819836555008LLU,18446454352143966718LLU,17365847176784920569LLU,288226527860881535LLU,18446744073709551615LLU,18446744069415632895LLU,18446744073709551615LLU,16777215LLU,18155118198412771072LLU,18445618190982578172LLU,18442258066065844191LLU,18438845149950705633LLU,40764LLU},{1733752233155126675LLU,143004951973584944LLU,1148434401815430659LLU,18416782764912144399LLU,11202971022038125351LLU,16542789227147952127LLU,18446744021028172489LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18428795919705834495LLU,2865199969088831487LLU,17874786864292954059LLU,65535LLU},{18444632908304981887LLU,18375812349513695231LLU,18379190079298994175LLU,14123281800003325951LLU,18446691020654460671LLU,11492974036829335567LLU,18410724072783597503LLU,18446744073709551615LLU,4294967295LLU,18442240474082181120LLU,18446744073709551615LLU,9799304991363629055LLU,13853072437685518335LLU,18176514901896330303LLU,14410990834770116414LLU,29951LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503458889882140671LLU,9216616637413720062LLU,18446744073709293560LLU,36024467684589567LLU,18446744005006852095LLU,18446744069414584575LLU,4503599627370495LLU,0LLU,8778051443493911296LLU,18446744073709551612LLU,18446744073473057742LLU,4607718430703777791LLU,40932LLU}};

uint_fast8_t X[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[27][16] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,174083477002518527LLU,7243828894392909822LLU,18446744073709289480LLU,4450727903231LLU,4095LLU,17587891077120LLU,4502500384112640LLU,1152921435904147455LLU,8388864LLU,9223372036854775804LLU,18446744073441124352LLU,18442240748943311871LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[27];
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
    cnt[20] = 0;
    cnt[21] = 0;
    cnt[22] = 0;
    cnt[23] = 0;
    cnt[24] = 0;
    cnt[25] = 0;
    cnt[26] = 0;

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
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[20]), "+r" (cnt[21]), "+r" (cnt[22]), "+r" (cnt[23])
            : "r" (buf[20]), "r" (buf[21]), "r" (buf[22]), "r" (buf[23]));
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[24]), "+r" (cnt[25])
            : "r" (buf[24]), "r" (buf[25]));
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[26])
            : "r" (buf[26]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23] + cnt[24] + cnt[25] + cnt[26];
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
    sprintf(str, "[                           ,%5d]\n", this);
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
    str[21] = X[20] ^ 48;
    str[22] = X[21] ^ 48;
    str[23] = X[22] ^ 48;
    str[24] = X[23] ^ 48;
    str[25] = X[24] ^ 48;
    str[26] = X[25] ^ 48;
    str[27] = X[26] ^ 48;

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
    fputs("[[0,1],[0,3],[0,14],[1,2],[1,8],[2,4],[2,6],[3,4],[3,7],[4,5],[5,6],[5,7],[6,8],[7,9],[8,10],[9,11],[9,14],[10,12],[10,16],[11,12],[11,15],[12,13],[13,15],[13,16],[14,17],[15,17],[16,17]]\n", fout);
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

