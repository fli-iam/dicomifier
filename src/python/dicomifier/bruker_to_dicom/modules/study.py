#########################################################################
# Dicomifier - Copyright (C) Universite de Strasbourg
# Distributed under the terms of the CeCILL-B license, as published by
# the CEA-CNRS-INRIA. Refer to the LICENSE file or to
# http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
# for details.
#########################################################################

from . import cached

GeneralStudy = [ # PS 3.3, C.7.2.1
    ("VisuStudyUid", "StudyInstanceUID", 1, None),
    ("VisuStudyDate", "StudyDate", 2, None),
    ("VisuStudyDate", "StudyTime", 2, None),
    ("VisuStudyReferringPhysician", "ReferringPhysicianName", 2, None),
    (
        "VisuStudyNumber", "StudyID", 2, 
        cached("__StudyID")(
            lambda d,g,i: [str(x) for x in d["VisuStudyNumber"]])),
    (None, "AccessionNumber", 2, lambda d,g,i: None),
    ("VisuStudyId", "StudyDescription", 3, None),
]

PatientStudy = [ # PS 3.3, C.7.2.2.html
    ("VisuSubjectWeight", "PatientWeight", 3, None),
    (None, "PatientSexNeutered", 2, lambda d,g,i: None),
]
