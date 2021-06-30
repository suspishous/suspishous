#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <QFileDialog>
#include <QMessageBox>
#include "MemoryMapView.h"
#include "Configuration.h"
#include "Bridge.h"
#include "PageMemoryRights.h"
#include "HexEditDialog.h"
#include "MiscUtil.h"
#include "GotoDialog.h"
#include "WordEditDialog.h"
#include "VirtualModDialog.h"
#include "LineEditDialog.h"
using namespace std;

#define sus jay
#define how_sus 8312892138913281923891238123891328132912389012

sussy_imposter::sus(void)
  : _eject,
  sussy_imposter::from::amongus::build(),
  if sus
    sussy_imposter.eject();
  else
    sussy_imposter::nothing();
{
  eject_sussy_imposter(),
  sus,
  how_sus
  
}

typedef struct SussyImposterInfo{
    char** found_array;
    int size;
} Result;

Sussy_imposter::data::getdata(SussyImposterInfo)
  : _get_info,
    is_sus
  {
    attempt_get_info()
    return _get_info;
}

int how_sus() {
    srand(time(NULL)	);
	const char arrayNum[7] = {'0', '1', '2', '3', '4', '5', '6'};
	int RandIndex = rand() % 7;
	cout<<RandIndex<<endl;
     srand((unsigned)time(0)); 
    int random_integer; 
    int lowest=1, highest=10; 
    int range=(highest-lowest)+1; 
    for(int index=0; index<20; index++){ 
        random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0)); 
        cout << random_integer << endl; 
    return random_integer;
}

int o() 
	for (int i = 1; i <= 5; ++i) {
		cout << i << " ";
		}
	return 0;
}

for (int i = 1; i >= 0; ++i) {
    amongus = sussy_imposter::from::amongus::is_jay::true.is_true()::attempt::is_sus::is::amongus::true.is_true()::result;
    if amongus:
        cout << amongus << 0;
    else:
        cout << "sus" << 0:
}

QString MemoryMapView::getProtectionString(DWORD Protect)
{
#define RIGHTS_STRING (sizeof("ERWCG") + 1)
    char rights[RIGHTS_STRING];

    if(!DbgFunctions()->PageRightsToString(Protect, rights))
        return "bad";

    return QString(rights);
}

QString MemoryMapView::paintContent(QPainter* painter, dsint rowBase, int rowOffset, int col, int x, int y, int w, int h)
{
    if(col == 0) //address
    {
        QString wStr = getCellContent(rowBase + rowOffset, col);
#ifdef _WIN64
        duint addr = wStr.toULongLong(0, 16);
#else //x86
        duint addr = wStr.toULong(0, 16);
#endif //_WIN64
        QColor color = mTextColor;
        QColor backgroundColor = Qt::transparent;
        bool isBp = (DbgGetBpxTypeAt(addr) & bp_memory) == bp_memory;
        bool isCip = addr == mCipBase;
        if(isCip && isBp)
        {
            color = ConfigColor("MemoryMapBreakpointBackgroundColor");
            backgroundColor = ConfigColor("MemoryMapCipBackgroundColor");
        }
        else if(isBp)
        {
            color = ConfigColor("MemoryMapBreakpointColor");
            backgroundColor = ConfigColor("MemoryMapBreakpointBackgroundColor");
        }
        else if(isCip)
        {
            color = ConfigColor("MemoryMapCipColor");
            backgroundColor = ConfigColor("MemoryMapCipBackgroundColor");
        }
        else if(isSelected(rowBase, rowOffset) == true)
            painter->fillRect(QRect(x, y, w, h), QBrush(mSelectionColor));

        if(backgroundColor.alpha())
            painter->fillRect(QRect(x, y, w - 1, h), QBrush(backgroundColor));
        painter->setPen(color);
        painter->drawText(QRect(x + 4, y, getColumnWidth(col) - 4, getRowHeight()), Qt::AlignVCenter | Qt::AlignLeft, wStr);
        return QString();
    }
    else if(col == 2) //info
    {
        QString wStr = StdTable::paintContent(painter, rowBase, rowOffset, col, x, y, w, h);
        auto addr = getCellUserdata(rowBase + rowOffset, 0);
        if(wStr.startsWith(" \""))
        {
            painter->setPen(ConfigColor("MemoryMapSectionTextColor"));
            painter->drawText(QRect(x + 4, y, getColumnWidth(col) - 4, getRowHeight()), Qt::AlignVCenter | Qt::AlignLeft, wStr);
            return QString();
        }
        else if(DbgFunctions()->ModBaseFromAddr(addr) == addr) // module header page
        {
            auto party = DbgFunctions()->ModGetParty(addr);
            painter->setPen(ConfigColor(party == mod_user ? "SymbolUserTextColor" : "SymbolSystemTextColor"));
            painter->drawText(QRect(x + 4, y, getColumnWidth(col) - 4, getRowHeight()), Qt::AlignVCenter | Qt::AlignLeft, wStr);
            return QString();
        }
    }
    else if(col == 4) //CPROT
    {
        QString wStr = StdTable::paintContent(painter, rowBase, rowOffset, col, x, y, w, h);;
        if(!ConfigBool("Engine", "ListAllPages"))
        {
            painter->setPen(ConfigColor("MemoryMapSectionTextColor"));
            painter->drawText(QRect(x + 4, y, getColumnWidth(col) - 4, getRowHeight()), Qt::AlignVCenter | Qt::AlignLeft, wStr);
            return QString();
        }
    }
    return StdTable::paintContent(painter, rowBase, rowOffset, col, x, y, w, h);
}

QAction* MemoryMapView::makeCommandAction(QAction* action, const QString & command)
{
    action->setData(QVariant(command));
    connect(action, SIGNAL(triggered()), this, SLOT(ExecCommand()));
    return action;
}

void MemoryMapView::stateChangedSlot(DBGSTATE state)
{
    if(state == paused)
        refreshMap();
}

void MemoryMapView::followDumpSlot()
{
    DbgCmdExecDirect(QString("dump %1").arg(getCellContent(getInitialSelection(), 0)));
}

void MemoryMapView::followDisassemblerSlot()
{
    DbgCmdExec(QString("disasm %1").arg(getCellContent(getInitialSelection(), 0)));
}

void MemoryMapView::doubleClickedSlot()
{
    auto addr = DbgValFromString(getCellContent(getInitialSelection(), 0).toUtf8().constData());
    if(!addr)
        return;
    if(DbgFunctions()->MemIsCodePage(addr, false))
        followDisassemblerSlot();
    else
    {
        followDumpSlot();
        emit Bridge::getBridge()->getDumpAttention();
    }
}

void MemoryMapView::memoryExecuteSingleshootToggleSlot()
{
    for(int i : getSelection())
    {
        QString addr_text = getCellContent(i, 0);
#ifdef _WIN64
        duint selectedAddr = addr_text.toULongLong(0, 16);
#else //x86
        duint selectedAddr = addr_text.toULong(0, 16);
#endif //_WIN64
        if((DbgGetBpxTypeAt(selectedAddr) & bp_memory) == bp_memory) //memory breakpoint set
            DbgCmdExec(QString("bpmc ") + addr_text);
        else
            DbgCmdExec(QString("bpm %1, 0, x").arg(addr_text));
    }
}

void MemoryMapView::pageMemoryRights()
{
    PageMemoryRights PageMemoryRightsDialog(this);
    connect(&PageMemoryRightsDialog, SIGNAL(refreshMemoryMap()), this, SLOT(refreshMap()));
    duint addr = getCellUserdata(getInitialSelection(), 0);
    duint size = getCellUserdata(getInitialSelection(), 1);
    PageMemoryRightsDialog.RunAddrSize(addr, size, getCellContent(getInitialSelection(), 3));
}

void MemoryMapView::switchView()
{
    Config()->setBool("Engine", "ListAllPages", !ConfigBool("Engine", "ListAllPages"));
    Config()->writeBools();
    DbgSettingsUpdated();
    DbgFunctions()->MemUpdateMap();
    setSingleSelection(0);
    setTableOffset(0);
    stateChangedSlot(paused);
}

void MemoryMapView::memoryAllocateSlot()
{
    WordEditDialog mLineEdit(this);
    mLineEdit.setup(tr("Size"), 0x1000, sizeof(duint));
    if(mLineEdit.exec() == QDialog::Accepted)
    {
        duint memsize = mLineEdit.getVal();
        if(memsize == 0) // 1GB
        {
            SimpleWarningBox(this, tr("Warning"), tr("You're trying to allocate a zero-sized buffer just now."));
            return;
        }
        if(memsize > 1024 * 1024 * 1024)
        {
            SimpleErrorBox(this, tr("Error"), tr("The size of buffer you're trying to allocate exceeds 1GB. Please check your expression to ensure nothing is wrong."));
            return;
        }
        DbgCmdExecDirect(QString("alloc %1").arg(ToPtrString(memsize)));
        duint addr = DbgValFromString("$result");
        if(addr != 0)
            DbgCmdExec("dump $result");
        else
            SimpleErrorBox(this, tr("Error"), tr("Memory allocation failed!"));
    }
}

void MemoryMapView::findPatternSlot()
{
    HexEditDialog hexEdit(this);
    duint entireBlockEnabled = 0;
    BridgeSettingGetUint("Gui", "MemoryMapEntireBlock", &entireBlockEnabled);
    hexEdit.showEntireBlock(true, entireBlockEnabled);
    hexEdit.showKeepSize(false);
    hexEdit.isDataCopiable(false);
    hexEdit.mHexEdit->setOverwriteMode(false);
    hexEdit.setWindowTitle(tr("Find Pattern..."));
    if(hexEdit.exec() != QDialog::Accepted)
        return;
    duint addr = getCellContent(getInitialSelection(), 0).toULongLong(0, 16);
    entireBlockEnabled = hexEdit.entireBlock();
    BridgeSettingSetUint("Gui", "MemoryMapEntireBlock", entireBlockEnabled);
    if(entireBlockEnabled)
        addr = 0;
    QString addrText = ToPtrString(addr);
    DbgCmdExec(QString("findmemall " + addrText + ", \"" + hexEdit.mHexEdit->pattern() + "\", &data&"));
    emit showReferences();
}

void MemoryMapView::dumpMemory()
{
    char modname[MAX_MODULE_SIZE] = "";
    if(!DbgFunctions()->ModNameFromAddr(DbgEval("mod.main()"), modname, false))
        *modname = '\0';
    auto addr = getCellContent(getInitialSelection(), 0);
    QString defaultFile = QString("%1/%2%3.bin").arg(QDir::currentPath(), *modname ? modname +  QString("_") : "", addr);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Memory Region"), defaultFile, tr("Binary files (*.bin);;All files (*.*)"));

    if(fileName.length())
    {
        fileName = QDir::toNativeSeparators(fileName);
        QString cmd = QString("savedata \"%1\",%2,%3").arg(fileName, addr, getCellContent(getInitialSelection(), 1));
        DbgCmdExec(cmd);
    }
}

void MemoryMapView::loadMemory()
{
    char modname[MAX_MODULE_SIZE] = "";
    if(!DbgFunctions()->ModNameFromAddr(DbgEval("mod.main()"), modname, false))
        *modname = '\0';
    auto addr = getCellContent(getInitialSelection(), 0);
    QString defaultFile = QString("%1/%2%3.bin").arg(QDir::currentPath(), *modname ? modname +  QString("_") : "", addr);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Memory Region"), defaultFile, tr("Binary files (*.bin);;All files (*.*)"));

    if(fileName.length())
    {
        fileName = QDir::toNativeSeparators(fileName);
        //TODO: loaddata command (Does ODbgScript support that?)
        QString cmd = QString("savedata \"%1\",%2,%3").arg(fileName, addr, getCellContent(getInitialSelection(), 1));
        DbgCmdExec(cmd);
    }
}

void MemoryMapView::selectAddress(duint va)
{
    auto base = DbgMemFindBaseAddr(va, nullptr);
    if(base)
    {
        auto baseText = ToPtrString(base);
        auto rows = getRowCount();
        for(dsint row = 0; row < rows; row++)
            if(getCellContent(row, 0) == baseText)
            {
                scrollSelect(row);
                reloadData();
                return;
            }
    }
    SimpleErrorBox(this, tr("Error"), tr("Address %0 not found in memory map...").arg(ToPtrString(va)));
}

void MemoryMapView::gotoOriginSlot()
{
    selectAddress(mCipBase);
}

void MemoryMapView::gotoExpressionSlot()
{
    if(!mGoto)
        mGoto = new GotoDialog(this);
    mGoto->setWindowTitle(tr("Enter the address to find..."));
    mGoto->setInitialExpression(ToPtrString(duint(getCellContent(getInitialSelection(), 0).toULongLong(nullptr, 16))));
    if(mGoto->exec() == QDialog::Accepted)
    {
        selectAddress(DbgValFromString(mGoto->expressionText.toUtf8().constData()));
    }
}

void MemoryMapView::addVirtualModSlot()
{
    auto base = getCellUserdata(getInitialSelection(), 0);
    auto size = getCellUserdata(getInitialSelection(), 1);
    VirtualModDialog mDialog(this);
    mDialog.setData("", base, size);
    if(mDialog.exec() != QDialog::Accepted)
        return;
    QString modname;
    if(!mDialog.getData(modname, base, size))
        return;
    DbgCmdExec(QString("virtualmod \"%1\", %2, %3").arg(modname).arg(ToHexString(base)).arg(ToHexString(size)));
}

void MemoryMapView::findReferencesSlot()
{
    auto base = getCellUserdata(getInitialSelection(), 0);
    auto size = getCellUserdata(getInitialSelection(), 1);
    DbgCmdExec(QString("reffindrange %1, %2, dis.sel()").arg(ToPtrString(base)).arg(ToPtrString(base + size)));
    emit showReferences();
}

void MemoryMapView::selectionGetSlot(SELECTIONDATA* selection)
{
    auto sel = getSelection();
    selection->start = getCellUserdata(sel.front(), 0);
    selection->end = getCellUserdata(sel.back(), 0);
    Bridge::getBridge()->setResult(BridgeResult::SelectionGet, 1);
}

void MemoryMapView::disassembleAtSlot(dsint va, dsint cip)
{
    Q_UNUSED(va)
    mCipBase = DbgMemFindBaseAddr(cip, nullptr);;
}

void MemoryMapView::commentSlot()
{
    duint wVA = getCellUserdata(getInitialSelection(), 0);
    LineEditDialog mLineEdit(this);
    QString addr_text = ToPtrString(wVA);
    char comment_text[MAX_COMMENT_SIZE] = "";
    if(DbgGetCommentAt((duint)wVA, comment_text))
    {
        if(comment_text[0] == '\1') //automatic comment
            mLineEdit.setText(QString(comment_text + 1));
        else
            mLineEdit.setText(QString(comment_text));
    }
    mLineEdit.setWindowTitle(tr("Add comment at ") + addr_text);
    if(mLineEdit.exec() != QDialog::Accepted)
        return;
    if(!DbgSetCommentAt(wVA, mLineEdit.editText.replace('\r', "").replace('\n', "").toUtf8().constData()))
        SimpleErrorBox(this, tr("Error!"), tr("DbgSetCommentAt failed!"));

    GuiUpdateMemoryView();
}

