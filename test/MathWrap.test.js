const { expect } = require('chai');
const wrapper = require('../lib/binding').MathWrap;
let wrap = null;
let expectedId = null;

describe('add', () => {
    before(() => {
        wrap = new wrapper.MathWrap();
        expectedId = wrap.getId();
        console.log(`expected id: ${expectedId}`);
    });

    it('should add', (done) => {
        let value = wrap.add(22, 52);
        expect(value).to.equal(74);

        setTimeout(() => {
            expect(wrap.getId()).to.equal(expectedId);
            done();
        }, 2000);
    });

    it('should subtract', (done) => {
        let value = wrap.subtract(12, 4);
        expect(value).to.equal(8);

        setTimeout(() => {
            expect(wrap.getId()).to.equal(expectedId);
            done();
        }, 2000);
    })
});