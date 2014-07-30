/*************************************************************************
 * Dicomifier - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#define BOOST_TEST_MODULE SCU
#include <boost/test/unit_test.hpp>

#include "dicom/SCU.h"

BOOST_AUTO_TEST_CASE(Default)
{
    dicomifier::SCU scu;
    BOOST_CHECK_EQUAL(scu.get_own_ae_title(), "");
    BOOST_CHECK_EQUAL(scu.get_timeout(), 30);
    BOOST_CHECK_EQUAL(scu.get_peer_host_name(), "");
    BOOST_CHECK_EQUAL(scu.get_peer_port(), 104);
    BOOST_CHECK_EQUAL(scu.get_peer_ae_title(), "");
    BOOST_CHECK(scu.get_user_identity_type() == dicomifier::UserIdentityType::None);
    BOOST_CHECK_EQUAL(scu.get_user_identity_primary_field(), "");
    BOOST_CHECK_EQUAL(scu.get_user_identity_secondary_field(), "");
    BOOST_CHECK_EQUAL(scu.is_associated(), false);
    BOOST_CHECK_EQUAL(scu.get_affected_sop_class(), "");
}

BOOST_AUTO_TEST_CASE(OwnAETitle)
{
    dicomifier::SCU scu;
    scu.set_own_ae_title("LOCAL");
    BOOST_CHECK_EQUAL(scu.get_own_ae_title(), "LOCAL");
}

BOOST_AUTO_TEST_CASE(Timeout)
{
    dicomifier::SCU scu;
    scu.set_timeout(60);
    BOOST_CHECK_EQUAL(scu.get_timeout(), 60);
}

BOOST_AUTO_TEST_CASE(PeerHostName)
{
    dicomifier::SCU scu;
    scu.set_peer_host_name("remote.example.com");
    BOOST_CHECK_EQUAL(scu.get_peer_host_name(), "remote.example.com");
}

BOOST_AUTO_TEST_CASE(PeerPort)
{
    dicomifier::SCU scu;
    scu.set_peer_port(11112);
    BOOST_CHECK_EQUAL(scu.get_peer_port(), 11112);
}

BOOST_AUTO_TEST_CASE(PeerAETitle)
{
    dicomifier::SCU scu;
    scu.set_peer_ae_title("REMOTE");
    BOOST_CHECK_EQUAL(scu.get_peer_ae_title(), "REMOTE");
}

BOOST_AUTO_TEST_CASE(UserIdentityType)
{
    dicomifier::SCU scu;
    scu.set_user_identity_type(
        dicomifier::UserIdentityType::UsernameAndPassword);
    BOOST_CHECK(scu.get_user_identity_type() == 
        dicomifier::UserIdentityType::UsernameAndPassword);
}

BOOST_AUTO_TEST_CASE(UserIdentityPrimaryField)
{
    dicomifier::SCU scu;
    scu.set_user_identity_primary_field("username");
    BOOST_CHECK_EQUAL(scu.get_user_identity_primary_field(), "username");
}

BOOST_AUTO_TEST_CASE(UserIdentitySecondaryField)
{
    dicomifier::SCU scu;
    scu.set_user_identity_secondary_field("pAssw0rd!");
    BOOST_CHECK_EQUAL(scu.get_user_identity_secondary_field(), "pAssw0rd!");
}

BOOST_AUTO_TEST_CASE(UserIdentityNone)
{
    dicomifier::SCU scu;
    scu.set_user_identity_to_none();
    BOOST_CHECK(scu.get_user_identity_type() == 
        dicomifier::UserIdentityType::None);
}

BOOST_AUTO_TEST_CASE(UserIdentityUsername)
{
    dicomifier::SCU scu;
    scu.set_user_identity_to_username("username");
    BOOST_CHECK(scu.get_user_identity_type() == 
        dicomifier::UserIdentityType::Username);
    BOOST_CHECK_EQUAL(scu.get_user_identity_primary_field(), "username");
}

BOOST_AUTO_TEST_CASE(UserIdentityUsernameAndPassword)
{
    dicomifier::SCU scu;
    scu.set_user_identity_to_username_and_password("username", "pAssw0rd!");
    BOOST_CHECK(scu.get_user_identity_type() == 
        dicomifier::UserIdentityType::UsernameAndPassword);
    BOOST_CHECK_EQUAL(scu.get_user_identity_primary_field(), "username");
    BOOST_CHECK_EQUAL(scu.get_user_identity_secondary_field(), "pAssw0rd!");
}

BOOST_AUTO_TEST_CASE(UserIdentityKerboros)
{
    dicomifier::SCU scu;
    scu.set_user_identity_to_kerberos("i_can_haz_ticket");
    BOOST_CHECK(scu.get_user_identity_type() == 
        dicomifier::UserIdentityType::Kerberos);
    BOOST_CHECK_EQUAL(scu.get_user_identity_primary_field(), "i_can_haz_ticket");
}

BOOST_AUTO_TEST_CASE(UserIdentitySAML)
{
    dicomifier::SCU scu;
    scu.set_user_identity_to_saml("i_can_haz_sammich");
    BOOST_CHECK(scu.get_user_identity_type() == 
        dicomifier::UserIdentityType::SAML);
    BOOST_CHECK_EQUAL(scu.get_user_identity_primary_field(), "i_can_haz_sammich");
}

BOOST_AUTO_TEST_CASE(AffectedSOPClass)
{
    dicomifier::SCU scu;
    scu.set_affected_sop_class("1.2.840.10008.5.1.4.1.1.4");
    BOOST_CHECK_EQUAL(scu.get_affected_sop_class(), "1.2.840.10008.5.1.4.1.1.4");
}
