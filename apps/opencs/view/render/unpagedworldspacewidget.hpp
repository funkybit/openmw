#ifndef OPENCS_VIEW_UNPAGEDWORLDSPACEWIDGET_H
#define OPENCS_VIEW_UNPAGEDWORLDSPACEWIDGET_H

#include <string>
#include <memory>

#include "worldspacewidget.hpp"
#include "cell.hpp"

class QModelIndex;

namespace CSMDoc
{
    class Document;
}

namespace CSMWorld
{
    class IdTable;
}

namespace CSVRender
{
    class UnpagedWorldspaceWidget : public WorldspaceWidget
    {
            Q_OBJECT

            std::string mCellId;
            CSMWorld::IdTable *mCellsModel;
            CSMWorld::IdTable *mReferenceablesModel;
            std::auto_ptr<Cell> mCell;

            void update();

        public:

            UnpagedWorldspaceWidget (const std::string& cellId, CSMDoc::Document& document,
                                     QWidget *parent);

            virtual dropRequirments getDropRequirements(dropType type) const;

            virtual void handleDrop(const std::vector<CSMWorld::UniversalId>& data);

        private:

            virtual void referenceableDataChanged (const QModelIndex& topLeft,
                const QModelIndex& bottomRight);

            virtual void referenceableAboutToBeRemoved (const QModelIndex& parent, int start, int end);

            virtual void referenceableAdded (const QModelIndex& index, int start, int end);

            virtual void referenceDataChanged (const QModelIndex& topLeft, const QModelIndex& bottomRight);

            virtual void referenceAboutToBeRemoved (const QModelIndex& parent, int start, int end);

            virtual void referenceAdded (const QModelIndex& index, int start, int end);

        private slots:

            void cellDataChanged (const QModelIndex& topLeft, const QModelIndex& bottomRight);

            void cellRowsAboutToBeRemoved (const QModelIndex& parent, int start, int end);

        signals:

            void cellChanged(const CSMWorld::UniversalId& id);
    };
}

#endif
