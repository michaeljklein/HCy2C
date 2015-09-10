#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1186_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][17] = {{18446744073709551615LLU,549755813887LLU,17870283321406128128LLU,18446462598732873727LLU,18429011150176780287LLU,18446743798831644671LLU,18446465897267724351LLU,18446744073709551615LLU,18446735277616529407LLU,18446480190918884352LLU,18446744073709551615LLU,18374686479659040767LLU,18446744073709551615LLU,2305843009213693951LLU,18374686479671623680LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,576460752303423487LLU,0LLU,0LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU,0LLU,0LLU,16140901064495857664LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,0LLU,0LLU,0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,144115188075855871LLU,6341068275337658304LLU,18158399292510436606LLU,18227193561810467898LLU,16525950036543012863LLU,8962107724485557231LLU,15563258812524584831LLU,206LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{140737488355327LLU,18446743523953737728LLU,1152921504606846975LLU,18374686479671590912LLU,18446708803169663739LLU,18439414728325987503LLU,18446744073709551615LLU,18446744073709551615LLU,9223372036854775807LLU,11529214701124648959LLU,16427789966466604925LLU,18410499763819510767LLU,18446744073709551423LLU,16140901064495857679LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{0LLU,0LLU,17870283321406128128LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446181123755081729LLU,13817041177434324991LLU,18392699775413910015LLU,281474976710655LLU,18446673704965373952LLU,18158513697557839871LLU,18410996200766306303LLU,18446673670603275774LLU,17147401695477333887LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446739675663040767LLU,18410715276690585631LLU,63050325791080447LLU,18446744073709551360LLU,15LLU},{18446603336222244863LLU,17293541094125993983LLU,18445582989162184691LLU,18446744073709551615LLU,70368744177663LLU,504403158265495552LLU,18446744073709551552LLU,18311636084888436735LLU,18446744056529681663LLU,17293820370079450111LLU,18230536107190124543LLU,18446708889337462783LLU,4398046511071LLU,18446743944860532720LLU,18446145922204071931LLU,18446744073692774655LLU,15LLU},{281474976710655LLU,18446674804477001472LLU,2301331163198783455LLU,18412964877480820480LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU,18445618173802708992LLU,18446744073709551615LLU,13547109154107162623LLU,17870142583783555071LLU,18439847936779747324LLU,18446744073709543801LLU,4611686014132420623LLU,18372421481423175678LLU,18446744056546459478LLU,15LLU},{18446744073644539903LLU,18446743523953737983LLU,18014398483705876479LLU,18446603189655404799LLU,18012199385563135LLU,18442240473545047551LLU,18446744073709551615LLU,1125899906842623LLU,16140901064495857664LLU,18446744073709522943LLU,17293822569102704639LLU,14987979557875744767LLU,18446470841848823807LLU,16140901068790824959LLU,18410715000722161663LLU,18446726498703368447LLU,15LLU},{18446725931633474563LLU,18446744073709551615LLU,18403959737662569231LLU,527215624191999LLU,18446744073709543424LLU,18445688491007278977LLU,14119347781758877695LLU,18446730879570018303LLU,18446744073709551615LLU,2199023255551LLU,18428729675200069632LLU,18446744073709551615LLU,17291852244248953087LLU,18446744073172668188LLU,59671526556958719LLU,18445635760603267071LLU,15LLU},{18446744073708504063LLU,18438299824408224767LLU,18446532967477018623LLU,18446735277614956543LLU,18338587313908490239LLU,18446740775174668287LLU,18415218841958219007LLU,144115181633404927LLU,18446708889337462752LLU,18446744073709551615LLU,18014398509481983LLU,0LLU,13835027268973362944LLU,18410706618002962687LLU,18446532967477018503LLU,18375812259319381760LLU,15LLU},{14758190205928043519LLU,549755813695LLU,13835058055282163711LLU,18446744073676029818LLU,18445899234851454975LLU,12619086148372259839LLU,18446730879569756190LLU,18445758911261697009LLU,18446744073709551615LLU,18446742417974099960LLU,2305843009213693951LLU,18365960635130314496LLU,17829750778630242303LLU,2305843007061721079LLU,18446744073709535232LLU,17918697008097050588LLU,15LLU},{4611680795726184295LLU,18446744071695769587LLU,18446744073172680704LLU,16285016183885786583LLU,15849292988623618023LLU,18446726146516058111LLU,18446691296614809589LLU,18446743592438333439LLU,18446733112952488959LLU,9223319260296642439LLU,18446744056798115840LLU,18446744073709551615LLU,17293822569102131199LLU,18433110129382522879LLU,15708555465908568063LLU,9799671847067317759LLU,15LLU},{18392700874951479199LLU,18446744073575857151LLU,8646911285088223231LLU,2305561602956456959LLU,17856772522516152318LLU,16140901064495800319LLU,18446531868502261759LLU,16717361816799281039LLU,18446744071562592255LLU,18446532967475444863LLU,18446744073701165055LLU,18446744073700638975LLU,18437736874051960831LLU,18444632736506249215LLU,16645304257121091583LLU,9221013017410370547LLU,12LLU},{17294948400357179391LLU,18230558071680139263LLU,2305836171625758719LLU,18439985650607250428LLU,18446744073709551231LLU,576460752169205760LLU,36028790576500735LLU,18419722475944804352LLU,18442310825617129215LLU,18429855574570074111LLU,18446736377128157183LLU,18446744073709551615LLU,18158795172532451839LLU,9006917753992382463LLU,18446733628349087231LLU,9078940188909772799LLU,11LLU},{1152780835837870079LLU,18446691297151418112LLU,18446744073709436919LLU,18419722472723971843LLU,18446744039484030975LLU,18374686479805841407LLU,18446744073684385728LLU,9114159745891565567LLU,18446744073709551102LLU,18176525897580937199LLU,18302628885633695743LLU,18446735279764013055LLU,288230311727196159LLU,18446742866825838576LLU,18446744073608822782LLU,16703851001257656319LLU,7LLU},{18446744073659217023LLU,9006649633144831LLU,18446744073709551423LLU,18446744073543847935LLU,1152358554585915393LLU,18446744073709551519LLU,14984593064074150911LLU,18446744073709551615LLU,16140901066643341311LLU,18446744073709527033LLU,17275808170601611263LLU,18446744072098938627LLU,18445407065339068415LLU,16143152864309534527LLU,2305843009212104831LLU,17941340359862773757LLU,15LLU},{17365880098715205615LLU,18439988674268098559LLU,18446744073172811775LLU,16712858152746352636LLU,18372364345473499135LLU,4611686018293235711LLU,18419687291069922815LLU,18428729675199545471LLU,18446744073709092833LLU,18433198089920577439LLU,18446744073709549599LLU,8796093022207LLU,18176506174554209024LLU,18446667090713770495LLU,18158513663332319135LLU,11475171506539790111LLU,11LLU}};

static uint_fast64_t D[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18304880685447380991LLU,7818193848181430393LLU,18438001855716457479LLU,252764529086169087LLU,8655782077788126334LLU,18190566628318510104LLU,9224497419345858559LLU,16158635087280209919LLU,14987699167378276351LLU,4157109867734876423LLU,17687875173867161625LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{6149383816197701630LLU,15408317131283308885LLU,18144346953398148765LLU,18446744073709551615LLU,18446744073709551615LLU,18302628885633695743LLU,6269009112777250943LLU,15273631421746231003LLU,15770336710396139442LLU,3843268128100319231LLU,7448511204046992335LLU,15551894260339236474LLU,18446744073709551468LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446548818722816003LLU,8028510210962227199LLU,17182182137427112803LLU,6124216453035425791LLU,18446633346488677075LLU,18434840673513757357LLU,18446744073709551615LLU,18446744073709551615LLU,9223372036854775807LLU,14987976455386101760LLU,15633010045865139833LLU,13582464886769693647LLU,18446744073709551519LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{12297555512498585597LLU,13456660805173567146LLU,2143419808897265150LLU,18446297213991157760LLU,10628776595571081215LLU,247644364872576510LLU,18410156094282901376LLU,18445406414426593772LLU,17142854063807494271LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,576460752303423487LLU,18446462598732840960LLU,18446744073709551615LLU,18446744073709551615LLU,18302349609680240639LLU,12677067525968588727LLU,4016915510614405103LLU,18446181123756129280LLU,18445055119158660924LLU,18316139684499814885LLU,18446744073709551611LLU,3064711909056083951LLU,18403576374029953364LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,12392780274616762367LLU,18428860236814806958LLU,53902009206552571LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,18446465875707688959LLU,4598174382020262375LLU,8356991130725666623LLU,14289634205974675198LLU,16140901064495857654LLU,18417854179351221931LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,17870283321406128127LLU,12322974480392519679LLU,7818078205359344940LLU,18355118297108625235LLU,12214322940358950911LLU,3174450311246278455LLU,13203669410070245325LLU,18062243563932682239LLU,13811966897506971062LLU,7759129000310173109LLU,18446744073709551603LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{6149665291174412287LLU,16572780349604478293LLU,18156767586786664433LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18230571132396199807LLU,18304032547828344723LLU,2278398992599476223LLU,18446741874686296064LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8857718314197219327LLU,18409808427548029432LLU,18446744073692774655LLU,15LLU},{18445899648779419647LLU,11499374979529597951LLU,18379118057478027423LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18410715515489939711LLU,9799832789158199295LLU,16429061344898064359LLU,4610577710706589695LLU,16715250632200668956LLU,18304739947942377696LLU,18446744073709551481LLU,12617708742700431375LLU,56220120767524695LLU,18446744073709551360LLU,15LLU},{18446744073643205639LLU,8028510760718041087LLU,17941039063336208251LLU,143895065746997247LLU,66520325678982LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17293822569102672209LLU,18358887719457667299LLU,13979138056855209759LLU,18446466168176000991LLU,18446744073709551615LLU,18391961575233640107LLU,18446726498703368447LLU,15LLU},{18446689556212505595LLU,18446674254721187839LLU,18403951216388717511LLU,18411239175660273663LLU,18446730459193704447LLU,18419510833901442041LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18158514214973603502LLU,2161727821137838079LLU,4530901617766580220LLU,14289638879647490296LLU,2305843009213693942LLU,18362285012553367550LLU,18446744056546459478LLU,15LLU},{13839488904067022847LLU,18437807243198980156LLU,4179067749070163967LLU,18446589959006846568LLU,18313606409725411327LLU,1112385254818803199LLU,18446634061989411866LLU,140729137431425LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13835031667003097087LLU,18446735279708602367LLU,18410451092094582657LLU,18375812259309436671LLU,15LLU},{4608276707483320319LLU,16212892558552965059LLU,16132168502629891840LLU,18446688273246749079LLU,10653827868498329599LLU,17869174678677880704LLU,13870919513930928101LLU,18446726550008102911LLU,18414717241053405439LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17291852244265730047LLU,8857718448973662204LLU,18442511503696343550LLU,18445635760596435455LLU,15LLU},{18446739675650457479LLU,18446744073575342067LLU,18446744073709551615LLU,36028797018960351LLU,17437882755793813502LLU,18445868862353178599LLU,17563475596791513079LLU,18446730338403680255LLU,18446744071562067999LLU,288230272669839359LLU,18446744073701163008LLU,14987971862904963071LLU,9078655930240605959LLU,18444501069249637341LLU,16285016252571713535LLU,12682011343786605055LLU,14LLU},{18379084522156180479LLU,18446744073709550399LLU,4611686018427387903LLU,18426477875386384255LLU,9187343239827429503LLU,14917044567222976639LLU,4604930618986332127LLU,16202843145115795328LLU,18190566660530765823LLU,18227191530288857087LLU,17734023044399103LLU,18446744073709027328LLU,13819145922478599679LLU,17690138843430141555LLU,18446744073709551615LLU,8787648747027775472LLU,13LLU},{936747678799069055LLU,18446744071696285695LLU,18446744073709551615LLU,18433233274827436018LLU,14915921448374632417LLU,13835057986692775839LLU,14977846460727427068LLU,9169328841058410623LLU,18446741876833779704LLU,18379190071214465023LLU,18446744056538071039LLU,18437745533645750271LLU,16373874163090453503LLU,18430978124924181951LLU,16140901064495857663LLU,15469721781760358367LLU,15LLU},{18446744073709436215LLU,2304153745325193215LLU,17879079414428205311LLU,8790806566257819647LLU,18446744039358195686LLU,18446744073709551615LLU,18446743214684438271LLU,2305843009213693951LLU,16429129514623115262LLU,9223213707180375523LLU,18429011133257088992LLU,18446735277617053695LLU,18446744005517885439LLU,17283652636301590527LLU,5552727234183155687LLU,16703838751490572271LLU,7LLU},{18446744073709283023LLU,18160765465151007743LLU,18446743799360257855LLU,9799831745339579391LLU,18446740225416887839LLU,18446744073709551615LLU,18446744065554760191LLU,16717361816799281151LLU,18442242673071947751LLU,18446638520593284957LLU,17293813790189420575LLU,13844065254536888323LLU,18446743248871260159LLU,18176030841933660159LLU,12970364760148671519LLU,9078934880850542521LLU,11LLU},{17528001998383144959LLU,18446744073709551600LLU,9223090836227375095LLU,18446727526274301901LLU,18439922671352283135LLU,6917493911858388991LLU,18428624061526441971LLU,18446743524221656975LLU,18446744073709551615LLU,18446743944355643055LLU,18302628885633695743LLU,4611677359764422655LLU,2080659677502242560LLU,18446744073456253951LLU,18446464765443112959LLU,12634848752101588855LLU,14LLU},{18446612132272274879LLU,288177084071673615LLU,17870564796382838783LLU,9205093755529312063LLU,4025655116915794430LLU,18374721664043712511LLU,18444341709522091983LLU,18373561129520594943LLU,16145404662009298431LLU,18230428492523093499LLU,18428738471284834303LLU,18446744073709551615LLU,18446603336208478207LLU,16427442518041296752LLU,7998674413186696190LLU,18157870470358100991LLU,5LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18304880685447380991LLU,7818193848181430393LLU,18438001855716457479LLU,252764529086169087LLU,8655782077788126334LLU,18190566628318510104LLU,9224497419345858559LLU,16158635087280209919LLU,14987699167378276351LLU,4157109867734876423LLU,17687875173867161625LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,4],[2,6],[3,6],[3,7],[4,7],[4,8],[5,7],[5,8],[5,9],[6,8],[6,9],[7,9],[8,9]]\n", fout);
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
