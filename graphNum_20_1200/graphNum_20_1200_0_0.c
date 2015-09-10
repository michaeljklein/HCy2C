#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1200_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][17] = {{18446744073709551615LLU,140737488355327LLU,17870283321406128128LLU,18429151887665201151LLU,18446181123755737087LLU,18446691022273052671LLU,13943144446355832823LLU,18302628885633681407LLU,18446730879469355007LLU,18446744073709551087LLU,18445055207743160319LLU,18446744073709551103LLU,18446744073708498927LLU,18446744073709551615LLU,34359738367LLU,18446744072635809792LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,576460752303423487LLU,0LLU,0LLU,0LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU,0LLU,0LLU,18446744073709543424LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8191LLU,0LLU,0LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073692774431LLU,3455379658007838719LLU,16424275851270422520LLU,18437596132667305983LLU,8457760100134680318LLU,18446176828570623723LLU,2251558716684286LLU,18446708889337462784LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{72057594037927935LLU,18446603336221196288LLU,1152921504606846975LLU,18446744073709486080LLU,18120231311702474491LLU,6910772524124987375LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17797081684449951743LLU,17293505359452569567LLU,16068707125913321439LLU,18446451878426836727LLU,35184372088831LLU,18446744039349813248LLU,18446744073709551615LLU,68719476735LLU},{0LLU,0LLU,17870283321406128128LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073575333889LLU,18445055222238674943LLU,18410715242297196527LLU,140737488355327LLU,18374686479671623680LLU,18446744073709551615LLU,18446744065119551551LLU,9223372036854775807LLU,17870283319392862206LLU,18446740775174438911LLU,18446673722143670271LLU,18014397684713979903LLU,4450754349760511LLU,18446744073709518848LLU,9187343033677185023LLU,18446739676602560479LLU,68719476735LLU},{9439544819102777343LLU,17870265729186529279LLU,18444485676289228287LLU,18446744073709551615LLU,72057594037927935LLU,0LLU,4611118670410743792LLU,18444487875849354752LLU,17293822569102180345LLU,14987979559885078431LLU,18446744073709551615LLU,18446740775174668287LLU,18446743936270597663LLU,18442275658454302719LLU,18446673700670406655LLU,18428734073246318591LLU,68719476735LLU},{143692975610789887LLU,18410715276690522112LLU,2288953960855224569LLU,18446726481322180480LLU,18446744073709551615LLU,18441184942919516159LLU,36028797018963967LLU,16140901064495857664LLU,18446744073709551615LLU,18446743944801812479LLU,18446744073709490175LLU,18429829186290697215LLU,18446742408335982591LLU,34772055228415LLU,14398003610656964544LLU,16497072412753919LLU,68719476735LLU},{18446743042917400451LLU,16140760327007567871LLU,18446691297151418367LLU,18013298997788799LLU,18446742974197923839LLU,18446744073642966527LLU,18446744073709551615LLU,2305843009213693951LLU,0LLU,18446744072702910464LLU,18176527889908891641LLU,18446638520593285119LLU,18167520896812457983LLU,18446744072761638911LLU,18446462564373102655LLU,18446744040422506495LLU,68719475712LLU},{18446741870659501311LLU,18446744069414584255LLU,18446744073709551615LLU,15852670688344145919LLU,90071976390950785LLU,14987838820379000824LLU,9223372036854775807LLU,16717361752173346751LLU,18439883056459284479LLU,1983LLU,18446744073575333888LLU,18446744073709551615LLU,16339059448100159487LLU,16563038621841506199LLU,18446744052191920095LLU,17816174086460538879LLU,68719346671LLU},{18446744073706930175LLU,18158787750818078079LLU,18446742991126126591LLU,18446743652800790527LLU,18446730621871980543LLU,18446744073709551615LLU,18446531317974695935LLU,18419668668595044351LLU,4476578029606149903LLU,18446744073709551612LLU,134217727LLU,18446744004990074880LLU,18446744073709551615LLU,11529215046068468351LLU,16140865912671561334LLU,14987978019069363983LLU,68702830202LLU},{18445618143737934847LLU,288230367560204287LLU,18446744073708765056LLU,17870283320837799935LLU,18446744073709518975LLU,18392700878181089287LLU,18446744035323281407LLU,18446744073707585532LLU,18446743042917396735LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,2265310612567359488LLU,18392277566138351614LLU,18158548881926781439LLU,18227826910572838908LLU,67662512093LLU},{18446733073480153855LLU,18446744073709548479LLU,18446744065119617151LLU,18443366305303101423LLU,9799709630970984935LLU,18446744020559200159LLU,17582017765177286655LLU,18446251440960696319LLU,18446744073709551615LLU,18302628886707437567LLU,2305276757504163839LLU,140737488355327LLU,13258597302977687534LLU,17293822558362990527LLU,288230376151711741LLU,13168441129072326656LLU,65464681471LLU},{17287067029001453047LLU,18446744069148246011LLU,8646911293141286911LLU,18361035012020632831LLU,9223372036850319263LLU,17942305731069607928LLU,14951985947240038143LLU,18446744073692766191LLU,18446735226001428479LLU,144115188075855871LLU,18445618160783589376LLU,18446744073676520959LLU,17293822569102704639LLU,18446741874685509631LLU,18446744073708996607LLU,18406158897283860479LLU,55832362979LLU},{9223372036854644863LLU,4611580465108746208LLU,2291839622679884795LLU,18446719850022665724LLU,18446744073172680704LLU,18446744073709551615LLU,18443339985173084223LLU,9223372034707292671LLU,17870283321398785023LLU,18320643180510240895LLU,18446744073709501959LLU,18433215132885581823LLU,288229263621095423LLU,17874786921033498592LLU,17283126494217878527LLU,17888297685516024831LLU,47043272703LLU},{18446252591877849087LLU,18436610869858074655LLU,18446744073705279487LLU,18446744071427581827LLU,18374686480208494591LLU,18441180544940113919LLU,18446743927679682559LLU,16140901066643341311LLU,18445635763975487482LLU,18446744073675341823LLU,288160282285441023LLU,18446744073709539264LLU,18446744073709551615LLU,576460272340795423LLU,16140899827519913920LLU,576456422976389119LLU,33285076991LLU},{9727845563861700607LLU,8376695306909122529LLU,4611399320770445311LLU,18446739400779366396LLU,18446730621335142399LLU,4398046511103LLU,18446744073559603312LLU,18446743246930443779LLU,18446744073709551615LLU,14987979559885799423LLU,18446744073709551167LLU,18446741256211005503LLU,18446744073577430559LLU,13326679131690105441LLU,18445514819709698047LLU,14682860685130104831LLU,47094693887LLU},{11466163826114592671LLU,18230430691546365927LLU,18446744065128005631LLU,1150669640367546364LLU,11529215045539987455LLU,576460752240377855LLU,17870248411765144048LLU,18446744071595617823LLU,1125899906842623LLU,18302910359802994688LLU,18230571152009330687LLU,18446744005023629311LLU,18230571291595767807LLU,18010990022630440935LLU,18446717651104301055LLU,18437728052591982607LLU,49379527807LLU}};

static uint_fast64_t D[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,10646509519103852543LLU,17956975480454749817LLU,1144616336655633895LLU,9223372036854775807LLU,572511567514468152LLU,16277732867700686840LLU,18446744072635811775LLU,16158861655655055359LLU,18446603403899965383LLU,15573445329486323327LLU,3463324285268860098LLU,18446744051906051995LLU,18446744073709551615LLU,68719476735LLU},{9079256848778919934LLU,11130313571469203775LLU,18278895288991849169LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18386566041418334175LLU,12635883849619537407LLU,13496934701900585647LLU,18275180491608928122LLU,8457689731254101748LLU,17845944358519658731LLU,18444418016553543676LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18332929158597042429LLU,7316660544616792063LLU,16968705328941596462LLU,18446518783817416703LLU,6014393863646426323LLU,6753142052684274509LLU,18446744073709551613LLU,18446744073709551615LLU,18446744073709551615LLU,12030186077705764863LLU,14983716169703488927LLU,11312892991957172126LLU,18445872779259018439LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{9481302140043140867LLU,18446514031333107392LLU,2222348281789081087LLU,7800741319474544640LLU,18360539062736650238LLU,17784026350630797311LLU,9355607663183921206LLU,8783976400789931719LLU,14409799167938916336LLU,18446744073709550031LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,576460752303423487LLU,18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,13907115649320091647LLU,18212380799427134463LLU,9133284066909140319LLU,17472250405525126373LLU,18444632994459770827LLU,14868634163318093823LLU,18446308656365633507LLU,14983440775889551359LLU,9695356872493039716LLU,18446744073320321706LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18429011150176780287LLU,12681248102329936815LLU,18122422880136885946LLU,18410715276690587651LLU,18446744073709551615LLU,18446744073709551615LLU,6903804917060730879LLU,4598164189967544958LLU,8934297184208157817LLU,2874387276979233726LLU,18446723086260691773LLU,8751387223020011519LLU,18446744073025039701LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,17870283321406128127LLU,10646228044127141887LLU,12518555221036026669LLU,12356319744104031410LLU,9151314442816847851LLU,15473627897009634104LLU,8986754277579601247LLU,6588121578104411829LLU,13452082246461512555LLU,7734650796942272373LLU,18445437825688722235LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{9367487224930631679LLU,17471683388178169855LLU,18299242869982756061LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17021433813139455LLU,18446744073709551104LLU,18338640313803897919LLU,13977172106014621568LLU,18444562642625351679LLU,14408061934970860031LLU,18446250939523268097LLU,18442275658454269951LLU,17793603097949883647LLU,18428734072960900794LLU,68719476735LLU},{9223372036854775807LLU,11527207061006686527LLU,18388109263885966307LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18441034845053255679LLU,18167256756323860991LLU,4584664418520896463LLU,18320638919802092671LLU,18446673705097510849LLU,17874734144475365375LLU,18446674791590031359LLU,14983475960261640191LLU,1089026435181196132LLU,18446739676498748367LLU,68719476735LLU},{18405084701803937665LLU,14838797822232363007LLU,18122423154844860335LLU,68554637311999LLU,2305843009213693951LLU,17960355313886444670LLU,18446744073709551601LLU,18446744073709551615LLU,18446744073709551615LLU,4595673830589693951LLU,18160765233112023032LLU,4179339019517100031LLU,18159023664794567166LLU,18446723181969014783LLU,9042787628633554943LLU,18446744039750872405LLU,68719475712LLU},{18446222881283367167LLU,8582734989861322751LLU,18429005927496532088LLU,18446713012257816575LLU,16716310619258118535LLU,18445622037662659481LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14987979423522029567LLU,2304137657015271487LLU,18428867663909339192LLU,2882303744455737231LLU,18446743564736455485LLU,14106321730066710527LLU,16497072399876095LLU,68719476735LLU},{13238572378701619131LLU,132971111697645LLU,13835058055282163584LLU,9186780289848880981LLU,18441662130695307263LLU,18383110654261133311LLU,18302628881345260406LLU,18271042114508814071LLU,2305275660106461191LLU,18446744073709551084LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446742974197922815LLU,18158513730306963574LLU,16138647872039026687LLU,68289822460LLU},{18158513663256817775LLU,18446656097579137022LLU,16057406345673045503LLU,17427748547691772335LLU,8935730998902784LLU,18446744073709535232LLU,2005768642267865023LLU,7203221730953805820LLU,16717360719430418429LLU,18446744073709544351LLU,18446744073709551615LLU,18446744073709551615LLU,234187180623265791LLU,18383201097650028542LLU,18446744052230782943LLU,18175969544160411644LLU,68081834959LLU},{14976576112479518679LLU,18446743076725587731LLU,9223370945668763647LLU,14909166070207076090LLU,18446743799305338879LLU,14334711321220218879LLU,16717113456013997311LLU,18446742976093736847LLU,18303622843675316218LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18374686479671623679LLU,9654587162200374807LLU,16140901064252516351LLU,16717361599903303439LLU,68713031547LLU},{16708882176933863411LLU,18446744073441169401LLU,4611686018427387903LLU,18320643284143176799LLU,18438862568195334143LLU,17871405373018590719LLU,18446744073705864831LLU,2270376337481400289LLU,18446744073701163008LLU,18446744073709551615LLU,18392648032903495679LLU,18446744073676013511LLU,18437734692493958783LLU,13726123356468535034LLU,18446744073709518899LLU,18439987571535642623LLU,55428251632LLU},{13816748433589861311LLU,18446736307334934767LLU,18446744073709551615LLU,4035225266123943909LLU,18446603610629339263LLU,4610841526874931079LLU,18446744073700887550LLU,18446182221388316286LLU,143129817888325631LLU,18446744073709551612LLU,72053333430370303LLU,67679277055LLU,11349071060973649918LLU,8914725640495690223LLU,18446744071812546556LLU,11457086241472774143LLU,65439268607LLU},{18446673739325112319LLU,18430976406943694847LLU,18014398303114887071LLU,18446673555698083839LLU,18446744073709551615LLU,18446739675663056895LLU,18428587629826146303LLU,18446744073709551615LLU,18337532882257346363LLU,18446466996644347900LLU,70368612057087LLU,576389284047617984LLU,18442310705387405310LLU,18446744005057183743LLU,18230569366213095167LLU,18446181122950799155LLU,33285076538LLU},{18405085766955827199LLU,71925639504461823LLU,18446182214945472511LLU,18446735775288491519LLU,2305843009213693951LLU,17960355313953537150LLU,18442488928410796017LLU,18446744073709551615LLU,18446743197527961855LLU,281474169298947LLU,18446744067267100160LLU,18446744006030786047LLU,18446744073575333889LLU,18446723182975647743LLU,18444501037773986303LLU,18430814349238073596LLU,47043272133LLU},{18446744073634054127LLU,16140900927325287359LLU,17888244943349104519LLU,17427698001345766319LLU,18383622210670559231LLU,18446744073709551615LLU,15821145217148346367LLU,16176437228765970431LLU,18445618173811097599LLU,18446462735936913407LLU,18446744073575399417LLU,17908845393215487LLU,18388199477576888318LLU,17293822569102688255LLU,4341188565774925773LLU,18446741250908356592LLU,32715502479LLU},{18446691277706622463LLU,18436610974547906559LLU,17870846271359549312LLU,18437604933034049439LLU,18374827217159948191LLU,18446739744382501881LLU,16109375863882465279LLU,16141464014447706109LLU,18446744073709551615LLU,18446744073675341823LLU,18445552194380890623LLU,18446744073709551552LLU,8065946932754776063LLU,18410433750123384830LLU,18160764260420943811LLU,9042908092810919935LLU,24963907583LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,10646509519103852543LLU,17956975480454749817LLU,1144616336655633895LLU,9223372036854775807LLU,572511567514468152LLU,16277732867700686840LLU,18446744072635811775LLU,16158861655655055359LLU,18446603403899965383LLU,15573445329486323327LLU,3463324285268860098LLU,18446744051906051995LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,6],[2,7],[3,6],[3,8],[4,5],[4,7],[4,9],[5,8],[5,9],[6,7],[6,9],[7,8],[8,9]]\n", fout);
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

