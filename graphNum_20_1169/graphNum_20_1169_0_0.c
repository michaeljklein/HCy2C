#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1169_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][16] = {{18446744073172680705LLU,17293822568037351423LLU,18446461499216740287LLU,17179869183LLU,18446726481523507200LLU,72057594037927935LLU,18446744073709551612LLU,17293892937846882303LLU,9259400833873739775LLU,18445055223849287679LLU,18439982070756272127LLU,18338657579573444607LLU,18446744004990075135LLU,18446744005526945791LLU,1143879120836884477LLU,1152921504606846848LLU},{18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,0LLU,0LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU,0LLU,0LLU,18437736874454810624LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9007199254740991LLU,0LLU,0LLU,0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18302628885633695744LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,17865779721778753536LLU,13835053587404159871LLU,17431618154004447LLU,16131858128965730176LLU,9187308021070397407LLU,17869719821157916639LLU,223LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{144115188075855871LLU,18445618173802708992LLU,72057594037927935LLU,17284815369847955456LLU,9223363101098768127LLU,18445578512998596543LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18158227755731255423LLU,17292695568609442814LLU,18428712065817116411LLU,18446744073709551614LLU,18374686479671623680LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,1125899906842623LLU,18410715276690587648LLU,9223371950955438079LLU,18446672588273729499LLU,18437736324547964415LLU,13835058012332494847LLU,18446708330991640557LLU,18442240199128758015LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU,17293822569102704640LLU,1152921504606846975LLU},{0LLU,0LLU,18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{432345564764438527LLU,18442240474082181116LLU,18442222812102917115LLU,18446744073709551615LLU,17592186044415LLU,18428729675200069632LLU,18445618242522181635LLU,18446744073709551615LLU,9223372036854775807LLU,18446744073306898304LLU,18446744073703260153LLU,18446638520492620287LLU,68719476729LLU,18302628885633695489LLU,18302063702297247615LLU,1152921504606584959LLU},{288230239786500095LLU,13835058055277969408LLU,142984890104610559LLU,18446744073709551608LLU,16141041801984212991LLU,18446744073709551615LLU,8589934591LLU,18446735277616529408LLU,18446744073709551615LLU,18392700878181040383LLU,18230359979204607999LLU,14987976261354127359LLU,18446726618962460671LLU,18446744073441116160LLU,18410574538629701623LLU,1152921504338673535LLU},{18446744073709551107LLU,18427603775297421311LLU,18428659027283013615LLU,18444492411334811655LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8796093022207LLU,18437736874454810624LLU,18446744060807938047LLU,18446744073508224831LLU,18443366370767749119LLU,18446744073709486399LLU,17798225727636635647LLU,16715101083453488639LLU,1152921229997375487LLU},{18428728850566348799LLU,2111055882878975LLU,18446744073707454464LLU,18446744073692790783LLU,18446744073709551615LLU,18446532967477018608LLU,18446744073701171199LLU,9223372036854775807LLU,18446638520593285112LLU,16777215LLU,18446462598732840960LLU,18446744073709551615LLU,16140795511379591167LLU,63049982466326527LLU,18446744073642442752LLU,1152912913866882303LLU},{18446744073701159935LLU,18446744073709486055LLU,18410715276692684799LLU,18176528078904229887LLU,18446744073306898431LLU,18446744073709551615LLU,18311636076306890751LLU,18446744073508225023LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,0LLU,18446744072635416320LLU,18446744073705355775LLU,10376293541528731647LLU,1152648825688817647LLU},{18445882049076658687LLU,18446737339142107139LLU,16285016252571713535LLU,2251799813684831LLU,18437877611943133184LLU,17365880146228740095LLU,1125899906842415LLU,18442310842826342400LLU,17365880154684686335LLU,18446744073709543935LLU,18446744073709551615LLU,18446744073709551615LLU,18336404920699256831LLU,18446313061393105151LLU,2305843009213693951LLU,1150872014916157432LLU},{18446743944324186111LLU,17906312117414268927LLU,2305842983443890175LLU,18446744073441017848LLU,16149890671564587007LLU,1152921504606846975LLU,18446744073575284732LLU,17298317372637069311LLU,10376293541461622783LLU,18446673722145185791LLU,18446744073709551615LLU,18446744073705422847LLU,18446727512382767103LLU,1152921439914164223LLU,18446743249075830783LLU,1137158081025671047LLU},{14411378207532974051LLU,18446742975271640575LLU,10952754293765046271LLU,18446735415055482759LLU,2305843009197178431LLU,14699749183703744512LLU,18446739744382517187LLU,1152921504598589215LLU,18446744073692774400LLU,18446744073707585520LLU,18446744073709551615LLU,18446744073709551615LLU,18428747266975068671LLU,18446673773683245041LLU,18446744073709551615LLU,1096624018452103423LLU},{4467711567839886879LLU,9222247236459560956LLU,18446744073206235134LLU,18444501069887955071LLU,18446744073709551615LLU,18428729675233624063LLU,18445622571798753343LLU,18446744073709551615LLU,18437736874471587839LLU,13907115649305411471LLU,288230376151711743LLU,18446744073709551552LLU,18014398509420543LLU,18374756848415801103LLU,18446744057603424207LLU,936440601539002367LLU},{9218305467896270783LLU,576421169733435167LLU,18158513697557839360LLU,288124823033477886LLU,18336968798969528312LLU,9079249137165139967LLU,144062411516738943LLU,18391856436339539964LLU,15924724426575183871LLU,70368744159743LLU,18446744073709289472LLU,18446744073709551615LLU,17798223247020908543LLU,18444210789230299103LLU,9223372036854759424LLU,791788009905192926LLU},{18446739121611767807LLU,18446744035021287679LLU,16717353055063900671LLU,18446744072084258815LLU,18439988674268463111LLU,17582052945254409203LLU,18446744072896905215LLU,18443366373989007363LLU,17582052945254412793LLU,18446744073709283325LLU,18446462598733103103LLU,18446739675667234815LLU,18446110205193224191LLU,18446741597660659711LLU,18446463698177376255LLU,557313854120392185LLU},{16140769123100506095LLU,18446743042917400431LLU,18410724072783609345LLU,18230564679492042655LLU,18446744073709551608LLU,18446744073676005375LLU,9115282339746021327LLU,18446744073709551612LLU,18302628885616922623LLU,4611686018425814003LLU,18446744073709289472LLU,4398046511103LLU,18429855575104550656LLU,18446678103011875831LLU,12682418025652011071LLU,827888262362681342LLU}};

static uint_fast64_t D[20][16] = {{288230376151711743LLU,4604207563389534204LLU,18438831883160582393LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18445618176636608511LLU,9223372036854775807LLU,18438756740076896312LLU,4053239664096706303LLU,16212747346134499320LLU,1152781866500094008LLU,18446744073709551608LLU,18184295733400698624LLU,18193553976142536487LLU,1152921504606584959LLU},{18158513697557839870LLU,3834092027103602215LLU,18425126802504338637LLU,18446744073709551615LLU,18446744073709551615LLU,18410715276690587647LLU,7444450166863568895LLU,4611672614802797435LLU,18426985741827304861LLU,11430028628226736383LLU,8826667863226613407LLU,12099477295658344350LLU,18446744073709551519LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18210077768529679357LLU,14614180790817259519LLU,18360274953857872690LLU,14888900333727137791LLU,9223345229605594870LLU,18443256206964022074LLU,18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,17578943319474437888LLU,14975582554463130612LLU,18248391986894861555LLU,18446744073709551604LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{524896681331584003LLU,18445215329498241496LLU,144115188075855871LLU,8932139238044975104LLU,15372259921212587419LLU,62758454698601967LLU,13689441655877263360LLU,16909501997461069517LLU,18442094504039888631LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,18446744056529682432LLU,18446744073709551615LLU,18446744073709551615LLU,11439143001981452287LLU,18446690459498467300LLU,18439917893094183546LLU,8754568754303598591LLU,16571415252921874814LLU,6888227014817971833LLU,18446744073709551486LLU,11987342645781957118LLU,17754991395142736294LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4431541930253352959LLU,18446636845287382985LLU,4362037278745845LLU,18446744065119617024LLU,18446744073709551615LLU,18446744073709551615LLU,14973289256418541567LLU,4553081992777773003LLU,17509079663313406927LLU,6600201084395454155LLU,6485183463413514239LLU,17985575247669519961LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16702349909667348479LLU,3074537766976483967LLU,18444995732643119007LLU,17574546991688450047LLU,10760640920343017791LLU,8133028721524687LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,11846542989314097663LLU,18420962038223631873LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18410715276690587647LLU,13072448575646990335LLU,12297882996600920941LLU,18423502282775443157LLU,15759596324678270975LLU,15372313535155236278LLU,18435123178242497386LLU,7884516199717928959LLU,13091237729729359211LLU,6545618864865897325LLU,18446744073709551467LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,16519203432124048935LLU,18428235156953862031LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1017813512951840767LLU,17293830387889211360LLU,18446744073709551615LLU,18444554812914532863LLU,18438009819693572159LLU,18303754649174818815LLU,18446744073709551423LLU,12105675729832348159LLU,560636168424780284LLU,1152921504606846848LLU},{18354192957319413249LLU,17266800971338481663LLU,18419333929241388966LLU,18444492279563665407LLU,18446744073709551615LLU,18430769406444241008LLU,18446744073709551615LLU,18446744073709551615LLU,18410715276690587647LLU,14409829941082324864LLU,2299081006000367367LLU,18334294713273616327LLU,6600201175771840519LLU,17582052945254416383LLU,16416697946121499869LLU,1152921229997375487LLU},{18446743936630461439LLU,11164423476251459583LLU,18440527347966179963LLU,2035627025903681535LLU,16140916702068871104LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU,18376875744358825983LLU,18167247951634374649LLU,13979063429529860607LLU,18446726527586009081LLU,6773413839565225983LLU,18247808849921658739LLU,1152921504338673535LLU},{10338803414823071943LLU,18446451182095187937LLU,4467570830351532031LLU,18159042012894981387LLU,16689902612872429567LLU,11455187005051305871LLU,18302893043302266501LLU,17568323343290990591LLU,18445758850219933639LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13648007863975044095LLU,18427999010390276195LLU,11529215046068469759LLU,1152648825688817647LLU},{8614822117066469179LLU,18446493377088575966LLU,14123288431433875455LLU,16428603262749373172LLU,1756966560349810751LLU,7061363825219469296LLU,17437673668229462394LLU,878483280174905375LLU,18446603878460817400LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14339330635644509695LLU,18430699489967110045LLU,18446744073709551615LLU,1152912913866882303LLU},{18354347438703116287LLU,17871813272508825599LLU,18412967042278752255LLU,18446744064649740287LLU,18446744073709551615LLU,18430769406679186556LLU,18446744069179645951LLU,9223372036854775807LLU,18438756740194369086LLU,18446673704968388502LLU,18446744073709551615LLU,4611686018423193600LLU,6619974792885829376LLU,25859276534710271LLU,17365879067923972095LLU,1137157830826810111LLU},{18445727575209672703LLU,9223364095460245503LLU,18446611616817471968LLU,18446744070988758623LLU,18446744073709551615LLU,18446744056562713587LLU,18446744072349155119LLU,18446744073709551615LLU,18446744065136132601LLU,72057594035044329LLU,288230375883538176LLU,18442244867837919231LLU,18316632265725050879LLU,18446235824459612159LLU,18442505453163002895LLU,1150871990773458431LLU},{18446744073533119487LLU,144115188074477495LLU,18446744073172811774LLU,2251799813558960127LLU,18446742119096750079LLU,18446744073709551615LLU,10349271943634255871LLU,18446743096403150847LLU,10880696699727118335LLU,13835059154793737727LLU,274877906943LLU,18446744073709551552LLU,18446744051126239231LLU,4611686018339171839LLU,6917529010465406912LLU,936440858992705419LLU},{18446744073705764863LLU,18338657682652630127LLU,10950634959332580895LLU,18230571285953347583LLU,18446744073692806656LLU,14699749183737298943LLU,9115285642976673791LLU,18446744073701179136LLU,16861477004875137023LLU,18446742991377781759LLU,18446743799099818239LLU,13839557261153861631LLU,18446744073224847359LLU,14987979559887117311LLU,13767239353443271679LLU,1096624035339960308LLU},{17185728412474408695LLU,18445899588110893053LLU,13835049259726012415LLU,18445053572568575979LLU,16717346423621812223LLU,16123168140963078159LLU,18445898823139063797LLU,17582045248665681919LLU,18437877611943161863LLU,18446744073700769724LLU,18446744073709551615LLU,18446739675663040575LLU,4610692025287670783LLU,18392696995395403643LLU,18446462615912710143LLU,547152029693113343LLU},{2297856130916810639LLU,18446681676222857215LLU,9189595039246843903LLU,18446605526587406782LLU,18311636050545475583LLU,4611677239481204735LLU,18446674800148479199LLU,18379190062127513599LLU,16140896675022766079LLU,18446744073704292311LLU,18446744073709551615LLU,4611686018427387840LLU,17424423651708487424LLU,18442750634561109959LLU,17365880150255730687LLU,787971562065059791LLU},{18311635977044098687LLU,18013342977476785148LLU,17293822569100738559LLU,18444633011375761401LLU,16278243295304319487LLU,17852277718989668351LLU,18445688542542656508LLU,17362493684506935551LLU,13249594501770510335LLU,18446674804468576191LLU,18446462873610747903LLU,18446744073709551615LLU,1152907700531576831LLU,4544131970094661439LLU,18446744073646637055LLU,423333210869268411LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][16] = {{288230376151711743LLU,4604207563389534204LLU,18438831883160582393LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18445618176636608511LLU,9223372036854775807LLU,18438756740076896312LLU,4053239664096706303LLU,16212747346134499320LLU,1152781866500094008LLU,18446744073709551608LLU,18184295733400698624LLU,18193553976142536487LLU,1152921504606584959LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,5],[2,6],[3,5],[3,6],[4,7],[4,8],[5,7],[5,9],[6,8],[6,9],[7,8],[7,9],[8,9]]\n", fout);
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
