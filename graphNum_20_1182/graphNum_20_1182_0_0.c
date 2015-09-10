#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1182_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][16] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2199023255551LLU,0LLU,0LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,0LLU,0LLU,18446673704965373952LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU,0LLU,0LLU,18446741874686296064LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{0LLU,0LLU,18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18444492273895866368LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17293963306591059967LLU,18446741878981263359LLU,2881729266691604479LLU,18446742424240722937LLU,18407855996564144127LLU,15770883506776308654LLU,3860933922256765LLU,18446462598732840960LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{2251799813685247LLU,18446462598732840960LLU,72057594037927935LLU,15987180542839748608LLU,18446480044319538653LLU,18446744073239588847LLU,18446744073709551615LLU,18446744073709551615LLU,18437728078361788415LLU,15848095551741491182LLU,18445615904918003581LLU,18446742896752049919LLU,281474976710655LLU,18446744056529682432LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,281474976710655LLU,18410715276690587648LLU,18446742974197925887LLU,18446744073709551615LLU,1152921504606846975LLU,18446744071562067968LLU,18446744073709551615LLU,18442258066268225535LLU,13835057917784489983LLU,4611685605976178687LLU,18446603198781980671LLU,18446744073709551615LLU,17179869183LLU,18446744073709486080LLU,268435455LLU},{18437736874453762049LLU,16933391479864229855LLU,18443331185858838283LLU,1099511627775LLU,18446735277616529408LLU,16140619589519147007LLU,18446735268741373951LLU,7926335344103915511LLU,18446742836607694555LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU,18446744073701163008LLU,9222879455645532159LLU,18446744065119674366LLU,268435455LLU},{18444492273896914943LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8796093022207LLU,17294315150311948288LLU,18446741891866165247LLU,18419722415815786495LLU,4503582447468543LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446462598741229567LLU,18446744071561969551LLU,18445618182392643583LLU,268435455LLU},{4503599627370495LLU,18446744073701163008LLU,144115188075855871LLU,18446735277616529344LLU,18446739675653603327LLU,18446724248132124155LLU,2147483647LLU,18446744072635809792LLU,13835058055282163711LLU,18446744056596200959LLU,18014398509481983999LLU,18433514749804150720LLU,96198136425471LLU,18446744073709551608LLU,16142026959905947647LLU,268435455LLU},{18446730604677431295LLU,281474985099263LLU,18446744073709551608LLU,18446744073709488191LLU,18438616483757031423LLU,18446744066863267839LLU,18446744073709551615LLU,1073741823LLU,18446741874686296064LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446708906517331975LLU,2305785774479507455LLU,268435200LLU},{18446462585579502595LLU,18446744073709551615LLU,18444210780648766431LLU,2060443320319LLU,17582052945254416128LLU,18446740225418854272LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU,18446744056529682432LLU,4503599627370495LLU,18446691293057777648LLU,8645715015900332031LLU,17779085428918376443LLU,268431615LLU},{18446744073708504063LLU,18439988674033610751LLU,18446741872538812223LLU,18446744073709551615LLU,18446735277616529663LLU,18446744073709551615LLU,18446744073708503039LLU,18445618242522161151LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU,18442240474082181120LLU,16140901064487469071LLU,18446321655086039167LLU,2305843000657313662LLU,268374014LLU},{4503599627370495LLU,18446743029965389808LLU,144115187807420423LLU,18446744073172745983LLU,18446744073709551615LLU,1152921504606846975LLU,2199023251456LLU,18446691297151418366LLU,18446216308124090311LLU,17942340914630361087LLU,13835058055282149375LLU,18443225621468254195LLU,18303191835587117055LLU,13835093239551490047LLU,18375812373868904447LLU,267976191LLU},{18446744071578843135LLU,18446744073701163023LLU,18410715276959023103LLU,18446742974734794688LLU,9232379236109504511LLU,18438299824408231935LLU,18446744071562072063LLU,18446744072635809793LLU,17361939513466683391LLU,18446744057553092607LLU,9223125471372247039LLU,18446744073709551567LLU,144115187840974783LLU,4611686018427387896LLU,16212957627606958080LLU,264761343LLU},{17311834770736414719LLU,11529201027295214655LLU,17437937486595490047LLU,18446744065652342012LLU,9223372036854775807LLU,4548635623610646528LLU,18437754346381524976LLU,18446744056529681423LLU,1152252999654408191LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,17574170546663325695LLU,18411273827993518047LLU,18222673499573452769LLU,255654399LLU},{1150671903816404975LLU,18446744073709551600LLU,1152921504338542591LLU,18442521948526215167LLU,18446744073707470847LLU,17365809794430009343LLU,9005137670434831LLU,2287825277809590270LLU,18446321861244485631LLU,18445635765987705855LLU,17870564796382838783LLU,18230571291595767807LLU,18311355709423351935LLU,13871086852300537279LLU,13770899352778178559LLU,217833467LLU},{4611606853518884743LLU,17879290452209704959LLU,16140835093795045375LLU,17293840126912225143LLU,18372364311113760767LLU,18301502843724496895LLU,17942340640534691647LLU,1125899904778239LLU,18446744073709547520LLU,17179869183LLU,18446744073709551584LLU,13853072453791645695LLU,4593671619917905919LLU,18302626961471586303LLU,18446567997226614015LLU,183500513LLU},{18446743996391652479LLU,576179346046189567LLU,18446744073709551608LLU,1152921504606796031LLU,18442099732315635456LLU,18446744073709520775LLU,18446744073709551615LLU,18446744073709551615LLU,9223369837831524351LLU,18446744073709551608LLU,18446744056529682463LLU,4611686018393833535LLU,18446744018948595696LLU,18446711071197626367LLU,18446744038515146751LLU,129954079LLU},{17582050883669196703LLU,18009894845228777471LLU,17870283321406013311LLU,17298326168726929407LLU,18446735281911496703LLU,18410715276657065983LLU,18438862705642176499LLU,18445622554669350911LLU,18446673704965369856LLU,1125899906841607LLU,18446744073709551584LLU,14118784831840059391LLU,18442239443281772543LLU,18419439764002292703LLU,9218855235568533503LLU,192774118LLU}};

static uint_fast64_t D[20][16] = {{12293440185850396669LLU,5394584019198073498LLU,133871514371714795LLU,18446742299021281280LLU,4351356849342119935LLU,10376539344166845439LLU,13176237292720396970LLU,7925209442986982247LLU,18446742834191218395LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{6156420690615468030LLU,13052441529488188773LLU,18427996154501717492LLU,18446744073709551615LLU,18446744073709551615LLU,8070309794759573503LLU,7905750281892488533LLU,13219654179233650397LLU,18446741285666479029LLU,17759337627347058687LLU,1935825434297480110LLU,18444834751281850217LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18443627270953238531LLU,18446462598732840959LLU,18367649275564634911LLU,11068050857741907967LLU,16996284387221465497LLU,18446739116710874958LLU,18446744073709551615LLU,18446744073709551615LLU,16902018197614493695LLU,11227259260107597644LLU,17848848957272022649LLU,18446722967830904063LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18410715276690587647LLU,7378694990655913983LLU,15545846910855517798LLU,18446643965491360945LLU,15811500572806217727LLU,15748624525198470586LLU,1544729903656463726LLU,7906891259964446899LLU,17108813755849600471LLU,18444170902388530070LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,15811500574953701375LLU,18370006815870397882LLU,18442244793734922095LLU,9943947725441597439LLU,18446743558078353407LLU,18444492020492312535LLU,562949953421311LLU,11001660599181354864LLU,18446744073709512749LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8608485552183836671LLU,15545860178304161655LLU,60454881181373LLU,18446744071562067968LLU,18446744073709551615LLU,15384296327097614335LLU,18391843259046125243LLU,1031086807258757607LLU,6156161204235531263LLU,18446649062066926741LLU,7445083485561159679LLU,18446744073709524946LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14757389981311827967LLU,18446466776870894796LLU,18446724247628572131LLU,18446741876833779711LLU,260346976019677183LLU,4598173277985112568LLU,9215365667857297894LLU,18012424334473428764LLU,12293980633407422012LLU,18446276135398755178LLU,18446744062676588687LLU,18446744073709551615LLU,268435455LLU},{6160924290242838527LLU,13815873226086790517LLU,18428578895932874238LLU,18446744073709551615LLU,18446744073709551615LLU,9223372036854775807LLU,5270513384645031253LLU,18412967009114186910LLU,2167344726015LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,11674456134051168255LLU,15613403450937589634LLU,18445618182392609453LLU,268435455LLU},{18433233274827440127LLU,16169959783265628111LLU,18442748444427681537LLU,18446744073709551615LLU,18446744073709551615LLU,14987979559889010687LLU,18446728680117882879LLU,18194278405508407281LLU,18446743833161563655LLU,9295429356224511999LLU,4611685485599524863LLU,18443225363769724867LLU,6772850889611804671LLU,4611136601741715325LLU,18446744065119669630LLU,268435455LLU},{18446728190904264711LLU,281474976710655LLU,18446744073709551608LLU,3689362888490682367LLU,18438017469835440947LLU,18446744065654628255LLU,18446744073709551615LLU,18446744073709551615LLU,18392683285995061247LLU,13771006967478734745LLU,18430950536067807459LLU,6160908757732422143LLU,18446741700721950421LLU,18446708906517331967LLU,2305785774479507455LLU,268435200LLU},{18445881484540090363LLU,18446744073709551615LLU,18439706869602562847LLU,18446728256211779583LLU,14096259137071730687LLU,18446709378949053560LLU,18446744073709551615LLU,18446744073709551615LLU,9290961215637422079LLU,18446744056529697919LLU,17767833026953215LLU,18428747267386113984LLU,18446466158214242751LLU,7445083502741028863LLU,16142026959905920978LLU,268435455LLU},{13905948757135982591LLU,18438299824141885683LLU,7178733751377219583LLU,18446743502199451545LLU,13797868173984268287LLU,17739080726867737599LLU,4539767820235371456LLU,18445618173936894078LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14323698614851862527LLU,16046325231802892291LLU,2305176078102003503LLU,268374014LLU},{4557141430081945599LLU,2278754615312359228LLU,11384594052546558206LLU,18446743831463073894LLU,8135541620612268031LLU,4166951290053590912LLU,13906991662097185855LLU,18411841176582520719LLU,18446744039614545919LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13491605803043389439LLU,17436235434475536382LLU,17778626468746621689LLU,268431615LLU},{18446744071562784951LLU,18446744073709551615LLU,18446744073709551615LLU,17365616280349966335LLU,9223379798129098752LLU,18438299824408231935LLU,18446744073709551615LLU,16419278983239041023LLU,17298324227169972735LLU,9223354719546638335LLU,18446463131560706016LLU,14933919047019397119LLU,18446744073447833472LLU,18446744062695005935LLU,16140899973574164479LLU,264761132LLU},{18446728190920322895LLU,18446743029965389823LLU,18446744073709551615LLU,1081145385545629439LLU,18446744009033138175LLU,18446744065151076231LLU,18446744073709551615LLU,2287759289932054527LLU,9223372036850585536LLU,17870300913592157056LLU,18429011150176763935LLU,3530822090712121407LLU,18446740514254986879LLU,18446744073588371871LLU,4611628842475323391LLU,267976147LLU},{18446744073709535719LLU,18336194773349986303LLU,18442748448454213625LLU,18442258066268225535LLU,18446744073707454479LLU,18446744073709551615LLU,18446744073280684031LLU,36024467572629503LLU,18446741909046034431LLU,18445618178064121855LLU,17870283321422905343LLU,18176528096067321855LLU,6917529027641079811LLU,18446725850162396285LLU,11529215046017338751LLU,214945657LLU},{18446744073709223615LLU,9362967080955018255LLU,18446743799100080127LLU,17365880155087551996LLU,18446743038890868720LLU,18446744073709551615LLU,18446744073709293567LLU,18445688542546885633LLU,18446181121612836927LLU,576460749065420799LLU,9223372036838014944LLU,14987961984849313743LLU,17437937757176889340LLU,4611678183454920703LLU,18230571288766578656LLU,255327150LLU},{18228882319865692159LLU,18446744073703259379LLU,8903616220410922943LLU,18446743242229940189LLU,10376293537168752639LLU,17847699352571576447LLU,4610699720526722044LLU,18446744072770026622LLU,285098967035805695LLU,18446744073708634104LLU,576460752303423487LLU,18446744073675997184LLU,17795762756763125759LLU,14981083422959599611LLU,17110861084455026662LLU,129941503LLU},{288105581463984127LLU,18446744073709421567LLU,14411448713715138431LLU,18446744013547503603LLU,18311628388305195007LLU,18192853378397110271LLU,17871408740243341059LLU,18446744073707455487LLU,18229234285456392191LLU,18446744073709436031LLU,17888051154433081343LLU,18442258066268225535LLU,1121382288402151871LLU,18167239421835870207LLU,18144782785896774687LLU,183455743LLU},{18444633009362566655LLU,9223108154055852016LLU,4575727589888360440LLU,18446743042414050255LLU,9362842887814905615LLU,17575227451947089919LLU,576459100922048767LLU,18446744072637906942LLU,17579517473588248575LLU,18446744060790177791LLU,18446744056546459647LLU,18446744073709551615LLU,18338393799660666867LLU,14123262027048681464LLU,16662473337330140159LLU,98563967LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][16] = {{12293440185850396669LLU,5394584019198073498LLU,133871514371714795LLU,18446742299021281280LLU,4351356849342119935LLU,10376539344166845439LLU,13176237292720396970LLU,7925209442986982247LLU,18446742834191218395LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,4],[2,6],[3,5],[3,7],[4,7],[4,8],[5,6],[5,9],[6,8],[6,9],[7,8],[7,9],[8,9]]\n", fout);
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

