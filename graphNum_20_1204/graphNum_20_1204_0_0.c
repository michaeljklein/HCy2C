#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1204_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][17] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2097151LLU,0LLU,0LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,0LLU,0LLU,0LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU,0LLU,0LLU,18446744073707454464LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{0LLU,0LLU,16140901064495857664LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{17870283321406128128LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18374686479638069375LLU,18446740222029854687LLU,18284311021914945589LLU,13186539706796867581LLU,17865920459265933293LLU,18428720723124420535LLU,13194103863023LLU,18446743798831644672LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{576460752303423487LLU,18302628885633695744LLU,4611686018427387903LLU,16140619589519015936LLU,18122379208909913989LLU,18419718059645205599LLU,18446744073709551575LLU,18446744073709551615LLU,18446744073709551615LLU,18437731379044155391LLU,18307123138799843327LLU,17149707378845806078LLU,18446734001406967773LLU,274877906943LLU,18446744039349813248LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,144115188075855871LLU,16140901064495857664LLU,18446673704965505023LLU,18442238240665632767LLU,9222948175097102335LLU,18428729675233624062LLU,13781014859749474303LLU,18446743517511286783LLU,18446744073709535039LLU,18446744066193358847LLU,18158509574389211135LLU,18446744073696964603LLU,18446744073709551615LLU,34359738367LLU,18446744073705357312LLU,268435455LLU},{18446744072635809793LLU,18433232450187427743LLU,18158405945418317823LLU,70368744177663LLU,18374686479671623680LLU,18446744073709551615LLU,18444487875849289983LLU,17365879061480538111LLU,18446743944860532351LLU,18446744073583718655LLU,18446744073709551615LLU,9798706889251356671LLU,17386027614207LLU,18443366373989023232LLU,18446744070488276988LLU,18446744039354003455LLU,268435455LLU},{17870283322479869951LLU,9799832784863231999LLU,18446744073707470847LLU,18446744073709551615LLU,72057594037927935LLU,0LLU,18446744047906258880LLU,18446741874686296055LLU,18446744073705355775LLU,18444501067975622655LLU,18442451588904648703LLU,18446744073709551615LLU,18446744073709551615LLU,18446726206645600767LLU,17906311087632941055LLU,18446462633092579327LLU,268435455LLU},{1148417355190099967LLU,18446744073642442752LLU,9223354573517488127LLU,18446743652802756352LLU,18446660510825775087LLU,18424789025525989119LLU,18014398509481983LLU,0LLU,18446744073709551584LLU,18446744009285042175LLU,14960957962124787231LLU,18446744073709551615LLU,18446744073709551615LLU,271656681455LLU,18446744073709551584LLU,18374954758357121151LLU,268435455LLU},{18446717685429960703LLU,18302628885700804607LLU,18446744073701162911LLU,18302628885633564927LLU,18446744073508224927LLU,18446744073474670077LLU,18446744073709551615LLU,18446744073709551615LLU,31LLU,18446743042915303424LLU,18338657648292921343LLU,18410719674736312319LLU,13834495105328742399LLU,18446744073705349119LLU,17293611428510433311LLU,72057387577507839LLU,268435455LLU},{2305772634024968163LLU,18446304269058441214LLU,18446744073709551615LLU,18410856014178942975LLU,9313435225256099839LLU,18445618165749645311LLU,36028797018963955LLU,18302628885583233022LLU,13904997972745125884LLU,1900031LLU,18446744073575333888LLU,18446744073709551615LLU,9223108154064109567LLU,18436602383514464494LLU,18446744063985434614LLU,18441321007454093311LLU,268435328LLU},{18446603336221196287LLU,286506341516605425LLU,18334153258391568368LLU,18446744073705619455LLU,18446744073709551615LLU,18444492145046847487LLU,18445829279833915343LLU,18446612106544410625LLU,4577909021222047743LLU,18446744073709551600LLU,134217727LLU,18446744039349813248LLU,18446744073709551615LLU,16644749929213853695LLU,18446708923221147455LLU,18371139936195903103LLU,268419199LLU},{18356671849099686175LLU,18446744054919069695LLU,18446110754747703311LLU,36027697008214015LLU,9222527611924627708LLU,16501189034685466560LLU,18446743863524589567LLU,18446744073709551615LLU,18446744073658236927LLU,18446744073709551615LLU,18446744073709551615LLU,34359738367LLU,18176791978857988096LLU,18446744047939293119LLU,558481538166027519LLU,14555633993547493374LLU,264257535LLU},{11419985162918690815LLU,18446304133766041599LLU,18446744004990083071LLU,18446744005023627735LLU,18446744073709551615LLU,16428831273822191615LLU,16285014057832939518LLU,18406352174033371135LLU,14121599576742821887LLU,1099511627647LLU,18446744073709551612LLU,18446479366285164543LLU,18446744065240788991LLU,11385098191545303039LLU,18014398458094591LLU,17581658907774812096LLU,255197176LLU},{9223156801008832483LLU,18446744073709551610LLU,16140901133215334399LLU,18411207926619308031LLU,9799832782707376127LLU,18446743964185821183LLU,2287830809727202303LLU,18446744073709551422LLU,18446744073709551615LLU,18446744073709551615LLU,144115180425445379LLU,11240981371381849088LLU,16428885150042947131LLU,18446667107810145278LLU,18446744073709551615LLU,18431544409901236287LLU,218102919LLU},{13835058054208684031LLU,9221964558622982135LLU,18374685861464768496LLU,18446744005523012607LLU,18374686479680012287LLU,18446744073709551615LLU,16716796942566232063LLU,18443260820872753407LLU,14987979559419199231LLU,2251799687856115LLU,18446744073709551612LLU,18446532383361467391LLU,2305843001689112575LLU,12681713238698622464LLU,18446709988547096447LLU,17795692435397410497LLU,255837177LLU},{18444496671925813239LLU,16717300171133681663LLU,18438862770603442172LLU,18439982073439837183LLU,18446743523961208799LLU,18446708889339559935LLU,18446637962243853311LLU,18446744073709551615LLU,18410785645162134271LLU,17311705025789034495LLU,18445898555710013439LLU,18446744073642475505LLU,1729311888166092799LLU,18446744073174777848LLU,18338650879416598527LLU,13186535379613679603LLU,197128941LLU},{17872535120162847679LLU,11529215046068454399LLU,18446744009249521139LLU,14123288366863613939LLU,18374687029427434495LLU,35184372088831LLU,18446742956988645312LLU,18446743799368512503LLU,18446744073709551615LLU,1150810440570241023LLU,18443297104756473852LLU,18446744039416922111LLU,18371308779950572031LLU,18194243153073012231LLU,13401559378234966015LLU,18425919323479474127LLU,125620219LLU},{18444773594241169279LLU,17293822569035612159LLU,18446744071360668669LLU,4611686015994167055LLU,18446743532543660028LLU,18446709026776391619LLU,18446743933046218751LLU,274877906943LLU,18446744073709551584LLU,17437832152237473791LLU,18428165694454497279LLU,18446744073643491327LLU,18289100494566064127LLU,288230375748747257LLU,9135547308635586528LLU,18410711976947744758LLU,193198079LLU}};

static uint_fast64_t D[20][17] = {{16954299389678280445LLU,18180945027425605791LLU,7761626121842163711LLU,18446615524230823936LLU,18360957667808575247LLU,8880085264713513215LLU,18417271054574551292LLU,3908553685859713023LLU,18410607990273994863LLU,18446744073708451391LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{2305843009213693950LLU,8912710330835298144LLU,17613413490351916575LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,6118339715339911039LLU,17288007757666969245LLU,12228658234900787125LLU,13184285714393985001LLU,11970427071908146509LLU,9166694530361457463LLU,18446739390938916591LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{17633345748527128835LLU,9799832789158199295LLU,13824291544438716896LLU,11192840260889608191LLU,6015365843895823093LLU,15483335744278976347LLU,18446744073709551575LLU,18446744073709551615LLU,18446744073709551615LLU,7898561676167872511LLU,18293875038370871291LLU,14555633954757479916LLU,18446734001406442905LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,16140901064495857663LLU,7254032362298671103LLU,12517164635714704890LLU,12530067138426613668LLU,12357877377504640939LLU,15696926703892420962LLU,6254221922244321242LLU,15810640756858345942LLU,6629186037140085430LLU,13171159662300165851LLU,18446741236597250934LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,18446673704965373952LLU,18446744073709551615LLU,18446744073709551615LLU,12393906174523604991LLU,11463543329658969466LLU,6335437943482966015LLU,18433226677757648663LLU,6917529019206308543LLU,17937098444002788606LLU,18446742365654351864LLU,354993271946084351LLU,14955397692242444347LLU,18446744073705541756LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8551209792469729279LLU,12674814846858647039LLU,3314154747345678326LLU,18428729675200069694LLU,18446744073709551615LLU,18446744073709551615LLU,10554942190742667263LLU,17582015407238479844LLU,13835053699776184211LLU,13864929587169845887LLU,18446744012820947764LLU,3491346410605903871LLU,18446744073709367171LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14843442159348088831LLU,17960223164722052992LLU,18411834552113691661LLU,18338657682652659651LLU,18014394382303228871LLU,18203094444478035984LLU,18446742974199036412LLU,18302685201244880895LLU,16689201121171079167LLU,4581816479271296967LLU,18091750862652071115LLU,18446744044570755012LLU,18446744073709551615LLU,268435455LLU},{16140901064495857663LLU,9492830443326498684LLU,17829605514344926911LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8786162200369692671LLU,10375844811861131248LLU,3738549678590119935LLU,18444492643263025151LLU,18446673704982122111LLU,9216561386954424319LLU,18446742148620021752LLU,15343732594369888255LLU,17878585763685136827LLU,18446462633090145151LLU,268435455LLU},{4611686018427387903LLU,9206201048849907587LLU,17942213921423226719LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9795885059901751295LLU,17294842915892235327LLU,14987979422735024127LLU,18430981109941530627LLU,1017813515771048351LLU,9257217753536757886LLU,18446743799896997887LLU,3454609459379175423LLU,14983123012968973948LLU,18446744039352427772LLU,268435455LLU},{18212524925241179591LLU,13258597302978740223LLU,18435977638120505222LLU,18160753384953217023LLU,2297117284672077055LLU,360287969922508796LLU,18446744073709551614LLU,18446744073709551615LLU,18446744073709551615LLU,9095556007865614335LLU,18444157955786964988LLU,18410715280984522625LLU,9762748460976570367LLU,18446744013572523839LLU,16392835943339393023LLU,72057387577323483LLU,268435455LLU},{18439495111602586427LLU,14987979559889010687LLU,18446726535109474809LLU,3745305543613874175LLU,16717344707796927487LLU,18442273487348047859LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9366959458493661183LLU,13977480887730699779LLU,11240984669439647743LLU,17936676231521493051LLU,18446744069732547556LLU,4392121930136682495LLU,18374954758357121063LLU,268435455LLU},{18419150489170473215LLU,63045444862620095LLU,18446744073709543424LLU,18446744073676058217LLU,18441252803235004543LLU,8971020374309307391LLU,18446744069442739711LLU,13240446534689472511LLU,18446708268713641967LLU,18446744073708484543LLU,18446744073709551615LLU,18446744073709551615LLU,18194542494576803839LLU,16645304214171025343LLU,18428729709559807039LLU,15924709520085876735LLU,265971583LLU},{18337514157273775873LLU,18406209177373105887LLU,17004631219521978367LLU,33259723388310LLU,72057594037927932LLU,16428831273822191552LLU,18435462843879849726LLU,8970604069588336639LLU,18446736347004665212LLU,18446744073709321343LLU,18446744073709551615LLU,18446744073709551615LLU,18428747267386114047LLU,18436610957368033791LLU,576460742639597558LLU,17001088593059360766LLU,266715062LLU},{859938488870330367LLU,18444500996974444528LLU,9090514841749913599LLU,18446721902014602239LLU,18383610107716370319LLU,18424788888354422015LLU,16922007919879105LLU,18446744073709547520LLU,70368471546623LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,9223372036854775807LLU,18446181189128552174LLU,18446744073173204991LLU,18442296824052252287LLU,268425417LLU},{18446598972534161663LLU,18365674332576808379LLU,18446744073709551615LLU,18446744073709481853LLU,18446744073701163011LLU,18444492145044750399LLU,18446744073709154767LLU,17582052944783867663LLU,18419660800214958051LLU,18446744073707713532LLU,70368744177663LLU,9771685291487132672LLU,16158899863684120071LLU,18426372182580985855LLU,18446744054243491821LLU,16130767948422840319LLU,215972991LLU},{18309920846538866687LLU,18446743936336659455LLU,18446744073709551615LLU,14843864371813152963LLU,18445635284751089660LLU,16145371678539513805LLU,18446744073693798399LLU,18442240474619048951LLU,18446744073172680735LLU,18446744073709551615LLU,18446730020576559103LLU,18446466992961748991LLU,13823236097686642687LLU,9259101736373542811LLU,18446744073709543455LLU,17365823881889185791LLU,254863359LLU},{18446739676736782335LLU,18320635586429320318LLU,16716363460241256127LLU,18446706965192009532LLU,72057594037927935LLU,18446744073707454464LLU,9209834847008784383LLU,1152919305047769086LLU,18446673842403540448LLU,18446743343563018239LLU,18446744073592082047LLU,9189592840626241535LLU,18446726756401413632LLU,18415214478269350399LLU,18437033156947803619LLU,14974468726645038079LLU,214908855LLU},{18446744073709550527LLU,18304880666656882703LLU,16284999759846964351LLU,14123252972041175024LLU,18446744073709548543LLU,18446744073709551615LLU,18429855505582129151LLU,18446743798831648767LLU,18446744073658236927LLU,18446743236188831759LLU,14906914766464220703LLU,36028797018963071LLU,18371308779950571520LLU,18159076647511261183LLU,11527244687408624895LLU,18415218864952441343LLU,100417471LLU},{9223372036854726647LLU,18446673842338267130LLU,18437754466498242463LLU,18439980427931273023LLU,18446744073708634079LLU,18446744073709551615LLU,2305704330088414207LLU,4503599627370302LLU,18410715277227458528LLU,18446743816011513855LLU,4557642820751196671LLU,18410993453132414960LLU,17870195369065840639LLU,9223295071040831487LLU,17280100663979679712LLU,10376293535648188414LLU,181403367LLU},{18014395205846630383LLU,13691013235950485503LLU,16149908212209418231LLU,18419660851752353791LLU,11458283351930044351LLU,2305843009211858431LLU,18428869295979853760LLU,18446744073709551615LLU,36028797018963967LLU,9221682361217843200LLU,18372381898870882300LLU,18446744043644763151LLU,17293681831614349311LLU,18446743833190332031LLU,18158495521264631807LLU,9223160922011467743LLU,100654491LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][17] = {{16954299389678280445LLU,18180945027425605791LLU,7761626121842163711LLU,18446615524230823936LLU,18360957667808575247LLU,8880085264713513215LLU,18417271054574551292LLU,3908553685859713023LLU,18410607990273994863LLU,18446744073708451391LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,6],[2,7],[3,8],[3,9],[4,5],[4,6],[4,8],[5,6],[5,9],[6,7],[7,8],[7,9],[8,9]]\n", fout);
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
