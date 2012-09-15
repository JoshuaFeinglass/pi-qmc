#include "ReportWriters.h"
#include "ReportWriterInterface.h"
#include "SimpleScalarAccumulator.h"
#include "PartitionedScalarAccumulator.h"

ReportWriters::ReportWriters(
        ReportWriterInterface<ScalarEstimator, SimpleScalarAccumulator>*
            scalarReportWriter,
        ReportWriterInterface<ArrayEstimator, ScalarAccumulator>*
            arrayReportWriter,
        ReportWriterInterface<AccRejEstimator, ScalarAccumulator>*
            accRejReportWriter)
:   scalarReportWriter(scalarReportWriter),
    arrayReportWriter(arrayReportWriter),
    accRejReportWriter(accRejReportWriter) {
}

ReportWriters::~ReportWriters() {
    delete scalarReportWriter;
    delete arrayReportWriter;
    delete accRejReportWriter;
}

void ReportWriters::startScalarReport(ScalarEstimator *est,
        SimpleScalarAccumulator *acc) {
    scalarReportWriter->startReport(est, acc);
}

void ReportWriters::reportScalarStep(ScalarEstimator* est,
        SimpleScalarAccumulator *acc) {
    scalarReportWriter->reportStep(est, acc);
}

void ReportWriters::startScalarReport(ScalarEstimator* est,
        PartitionedScalarAccumulator* acc) {
//    scalarReportWriter->startReport(est, acc);
}

void ReportWriters::reportScalarStep(ScalarEstimator* est,
        PartitionedScalarAccumulator* acc) {
//    scalarReportWriter->reportStep(est, acc);
}

void ReportWriters::startAccRejReport(AccRejEstimator* est,
        ScalarAccumulator *acc) {
    accRejReportWriter->startReport(est, acc);
}

void ReportWriters::reportAccRejStep(AccRejEstimator* est,
        ScalarAccumulator *acc) {
    accRejReportWriter->reportStep(est, acc);
}

void ReportWriters::startArrayReport(ArrayEstimator* est,
        ScalarAccumulator *acc) {
    arrayReportWriter->startReport(est, acc);
}

void ReportWriters::reportArrayStep(ArrayEstimator* est,
        ScalarAccumulator *acc) {
    arrayReportWriter->reportStep(est, acc);
}
